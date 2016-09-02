#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

//
//     sysinfo  --- show system base information \n\
//     cd     ---  change directory \n\
//     mkdir  ---  make directory   \n\
//     touch  ---  create a new file \n\
//     cat   ---  read a file \n\
//     rm     ---  Delete a directory or a file \n\
//     exit   ---  exit this system\n");
//

// 目录也是文件，目录和文件通过iparent这个inode序号进行连接
// 目录未设置最大范围
// http://blog.csdn.net/yueguanghaidao/article/details/7682612



#define BLOCKSIZE 512
#define BLOCKNUM  512
#define INODENUM  30
#define FILENAME "aa"

typedef struct{
    unsigned short blockSize;
    unsigned short blockNum;
    unsigned short inodeNum;
    unsigned short blockFree;
    unsigned short inodeFree;
}SuperBlock;

typedef struct{
    unsigned short inum; // inode的序号
    char fileName[10];
    unsigned short isDir;  // 0-file 1-dir
    unsigned short iparent;
    unsigned short length;    //if file->filesize  if dir->filenum
    unsigned short blockNum; // 当前的盘块序号
}Inode,*PtrInode;

//Fcb用于存储文件与 目录信息，主要用途：将一个目录下的所有文件(包括目录)写入到该目录对应的Block中
//这玩意儿其实就是目录项
typedef struct {
    unsigned short inum;
    char fileName[10];
    unsigned short isDir;
}Fcb,*PtrFcb;

// 位示图数据{

char blockBitmap[BLOCKNUM];
char inodeBitmap[INODENUM];

SuperBlock superBlock;

unsigned short currentDir; // 表示当前目录
FILE *fp; // 文件指针
// 各结构体的大小，用来分配内存空间及文件指针跳转
const unsigned short superBlockSize=sizeof(superBlock);
const unsigned short blockBitmapSize=sizeof(blockBitmap);
const unsigned short inodeBitmapSize=sizeof(inodeBitmap);
const unsigned short inodeSize=sizeof(Inode);
const unsigned short fcbSize=sizeof(Fcb);
const unsigned short behindDataBlock=superBlockSize+blockBitmapSize+inodeBitmapSize;
char        *argv[5];
int argc;


// 创建文件系统                                                          TODO(1)
void createFileSystem()
{
    long len; // 临时数据，表示区域长度
    PtrInode fileInode;
    if ((fp=fopen(FILENAME,"wb+"))==NULL)
    {
        printf("open file %s error...\n",FILENAME);
        exit(1);
    } // 打开文件失败就跳出

    // 初始化位示图
    for(len=0;len<BLOCKNUM;len++)
        blockBitmap[len]=0;

    for(len=0;len<INODENUM;len++)
        inodeBitmap[len]=0;

     // 将磁盘所有内容置0
    for (len=0;len<(behindDataBlock+inodeSize*INODENUM+BLOCKSIZE*BLOCKNUM);len++)
    {
        fputc(0,fp);
    }
    rewind(fp); // fp文件指针重回文件开头

    // 初始化超级块
    superBlock.blockNum=BLOCKNUM;
    superBlock.blockSize=BLOCKSIZE;
    superBlock.inodeNum=INODENUM;
    superBlock.blockFree=BLOCKNUM-1;
    superBlock.inodeFree=INODENUM-1;

    fwrite(&superBlock,superBlockSize,1,fp); // 将超级块内容写入文件

    /*================================================================================
        TODO:
            去掉inode里面的filename
    ================================================================================*/
    // 创建根目录
    fileInode=(PtrInode)malloc(inodeSize); //创建inode节点->root
    fileInode->inum=0;
    strcpy(fileInode->fileName,"/");
    fileInode->isDir=1;
    fileInode->iparent=0;
    fileInode->length=0;
    fileInode->blockNum=0;

    // 更新位示图数据
    inodeBitmap[0]=1;
    blockBitmap[0]=1;

    // 更新后的位示图数据写入文件
    fseek(fp,superBlockSize,SEEK_SET);
    fwrite(blockBitmap,blockBitmapSize,1,fp);
    fseek(fp,superBlockSize+blockBitmapSize,SEEK_SET);
    fwrite(inodeBitmap,inodeBitmapSize,1,fp);

    // 将inode写入文件
    fseek(fp,behindDataBlock,SEEK_SET);
    fwrite(fileInode,inodeSize,1,fp);

    fflush(fp); // 把缓冲区数据写入文件

    // 初始化当前目录->根目录
    currentDir=0;

}

// 打开文件系统
void openFileSystem()
{
    // 文件系统如果不存在，则创建，否则读取数据
    if((fp=fopen(FILENAME,"rb"))==NULL)
    {
        createFileSystem();
    }
    else
    {
        if ((fp=fopen(FILENAME,"rb+"))==NULL)
        {
            printf("open file %s error...\n",FILENAME);
            exit(1);
        }
        rewind(fp); // 重置文件指针
        // 读取超级块数据
        fread(&superBlock,superBlockSize,1,fp);

        // 读取位示图数据
        fread(blockBitmap,blockBitmapSize,1,fp);
        fread(inodeBitmap,inodeBitmapSize,1,fp);

        // 初始化当前目录->根目录
        currentDir=0;

    }
}

// 创建文件或目录                                                        TODO(1)
void createFile(char *name,int flag)
{
    // flag = 0 -> 创建文件
    // flag = 1 -> 创建目录
    int i,nowBlockNum,nowInodeNum;
    PtrInode fileInode=(PtrInode)malloc(inodeSize);
    PtrInode parentInode=(PtrInode)malloc(inodeSize);
    PtrFcb fcb=(PtrFcb)malloc(fcbSize);

    /*================================================================================
        TODO:
            创建可设定长度的文件
            使用连续存储方式
            需要找到符合长度要求的盘块
    ================================================================================*/
    // 可用的数据盘块
    for(i=0;i<BLOCKNUM;i++)
    {
        if(blockBitmap[i]==0)
        {
            nowBlockNum=i;
            break;
        }
    }

    // 可用的inode盘块
    for(i=0;i<INODENUM;i++)
    {
        if(inodeBitmap[i]==0)
        {
            nowInodeNum=i;
            break;
        }
    }

    // 初始化inode数据
    fileInode->blockNum=nowBlockNum;
    strcpy(fileInode->fileName,name);
    fileInode->inum=nowInodeNum;
    fileInode->iparent=currentDir;
    if(flag==0)
    {
        fileInode->isDir=0;
    }
    else
    {
        fileInode->isDir=1;
    }
    fileInode->length=0;

    // 写入文件系统
    fseek(fp,behindDataBlock+inodeSize*nowInodeNum,SEEK_SET);
    fwrite(fileInode,inodeSize,1,fp);

    // 更新超级块和位示图信息
    superBlock.blockFree-=1;
    superBlock.inodeFree-=1;
    blockBitmap[nowBlockNum]=1;
    inodeBitmap[nowInodeNum]=1;

    // 初始化目录项信息
    strcpy(fcb->fileName,fileInode->fileName);
    fcb->inum=fileInode->inum;
    fcb->isDir=fileInode->isDir;

    // 更新相关信息
    // 读取父目录信息
    fseek(fp,behindDataBlock+currentDir*inodeSize,SEEK_SET);
    fread(parentInode,inodeSize,1,fp);
    fseek(fp,behindDataBlock+INODENUM*inodeSize+parentInode->blockNum*BLOCKSIZE+parentInode->length*fcbSize,SEEK_SET);
    // 目录项写入父目录
    fwrite(fcb,fcbSize,1,fp);

    // 更新父目录信息并写入文件
    parentInode->length+=1;
    fseek(fp,behindDataBlock+currentDir*inodeSize,SEEK_SET);
    fwrite(parentInode,inodeSize,1,fp);

    // 释放临时变量
    free(fileInode);
    free(parentInode);
    free(fcb);
}


// 列出目录信息
void list()
{
    int i;
    // 临时的目录变量
    PtrFcb fcb=(PtrFcb)malloc(fcbSize);
    PtrInode parentInode=(PtrInode)malloc(inodeSize);

    // 读取当前目录inode数据
    fseek(fp, (behindDataBlock)+currentDir*inodeSize, SEEK_SET);
    fread(parentInode,inodeSize,1,fp);

    // 指针移到当前目录存储块
    fseek(fp, (behindDataBlock)
        +inodeSize*INODENUM+parentInode->blockNum*BLOCKSIZE,SEEK_SET);

    // 列出信息
    // 循环读取父目录下所有目录项的信息
    for(i=0;i<parentInode->length;i++)
    {
        fread(fcb,fcbSize,1,fp);
        printf("Filename: %-10s",fcb->fileName);
        printf("Inode number: %-2d    ",fcb->inum);
        if(fcb->isDir==1)
        {
            printf("Directory\n");
        }
        else
        {
            printf("File\n");
        }
    }

    // 释放临时变量
    free(fcb);
    free(parentInode);
}


// 找到inode序号
int findInodeNum(char *name,int flag)
{
    int i,fileInodeNum;
    PtrInode parentInode=(PtrInode)malloc(inodeSize);
    PtrFcb fcb=(PtrFcb)malloc(fcbSize);

    // 找到当前目录的inode块
    fseek(fp,behindDataBlock+currentDir*inodeSize,SEEK_SET);
    fread(parentInode,inodeSize,1,fp);

    // 找到当前目录的存储区
    fseek(fp,behindDataBlock+inodeSize*INODENUM+parentInode->blockNum*BLOCKSIZE,SEEK_SET);

    for(i=0;i<parentInode->length;i++)
    {
        fread(fcb,fcbSize,1,fp);
        if(flag==0)
        {
            if((fcb->isDir==0)&&(strcmp(name,fcb->fileName)==0))
            {
                fileInodeNum=fcb->inum;
                break;
            }
        }
        else
        {
            if((fcb->isDir==1)&&(strcmp(name,fcb->fileName)==0))
            {
                fileInodeNum=fcb->inum;
                break;
            }

        }
    }

    if(i==parentInode->length)
            fileInodeNum=-1;

    free(fcb);
    free(parentInode);
    return fileInodeNum;
}

void cd(char *name)
{
    int fileInodeNum;
    PtrInode fileInode=(PtrInode)malloc(inodeSize);
    if(strcmp(name,"..")!=0)
    {
        fileInodeNum=findInodeNum(name,1);
        if(fileInodeNum==-1)
            printf("This is no such directory...\n");
        else
        {
            currentDir=fileInodeNum;
        }
    }
    else
    {
        fseek(fp,behindDataBlock+currentDir*inodeSize,SEEK_SET);
        fread(fileInode,inodeSize,1,fp);
        currentDir=fileInode->iparent;

    }
    free(fileInode);
}

void cdParent()
{
    PtrInode fileInode=(PtrInode)malloc(inodeSize);
    fseek(fp,behindDataBlock+currentDir*inodeSize,SEEK_SET);
    fread(fileInode,inodeSize,1,fp);
    currentDir=fileInode->iparent;

    free(fileInode);
}

void open(char *name)
{
    int fileInodeNum;
    PtrInode fileInode=(PtrInode)malloc(inodeSize);
    if((fileInodeNum=findInodeNum(name,1))!=-1)
    {
            printf("This is a directory,not a file...\n");
            return;
    }
    fileInodeNum=findInodeNum(name,0);
    if(fileInodeNum==-1)
        printf("This is no such file...\n");
    else
    {
        // 找到该文件的inode
        fseek(fp,behindDataBlock+fileInodeNum*inodeSize,SEEK_SET);
        fread(fileInode,inodeSize,1,fp);
        // 打印文件长度
        printf("This file's size is %d.\n", fileInode->length);
    }

    free(fileInode);
}

// 删除文件or目录(不考虑unlink)
void Delete(char *name)
{
    int fileInodeNum,i;
    PtrInode fileInode=(PtrInode)malloc(inodeSize); // 文件inode
    PtrInode parentInode=(PtrInode)malloc(inodeSize); // 目录inode
    Fcb fcb[50];

    if(((fileInodeNum=findInodeNum(name,0))==-1)&&((fileInodeNum=findInodeNum(name,1))==-1))
    {
        printf("This is no %s...\n",name);
    }
    else
    {
        if((fileInodeNum=findInodeNum(name,0))==-1)
        {
            fileInodeNum=findInodeNum(name,1);
        }
        // 读取文件inode
        fseek(fp,behindDataBlock+fileInodeNum*inodeSize,SEEK_SET);
        fread(fileInode,inodeSize,1,fp);
        // 读取目录inode
        fseek(fp,behindDataBlock+fileInode->iparent*inodeSize,SEEK_SET);
        fread(parentInode,inodeSize,1,fp);

        // 保存所有的fcb
        fseek(fp,behindDataBlock+INODENUM*inodeSize+parentInode->blockNum*BLOCKSIZE,SEEK_SET);
        for(i=0;i<parentInode->length;i++)
        {
            fread(&fcb[i],fcbSize,1,fp);
        }

        // 清0当前目录
        fseek(fp,behindDataBlock+INODENUM*inodeSize+parentInode->blockNum*BLOCKSIZE,SEEK_SET);
        for(i=0;i<BLOCKSIZE;i++)
            fputc(0,fp);

        // 将fcb写入回去，略过被删除的fcb
        fseek(fp,behindDataBlock+INODENUM*inodeSize+parentInode->blockNum*BLOCKSIZE,SEEK_SET);
        for(i=0;i<parentInode->length;i++)
        {
            if((strcmp(fcb[i].fileName,name))!=0)
            {
                fwrite(&fcb[i],fcbSize,1,fp);
            }
        }

        // 更新父目录信息
        parentInode->length-=1;
        fseek(fp,behindDataBlock+fileInode->iparent*inodeSize,SEEK_SET);
        fwrite(parentInode,inodeSize,1,fp);
        // 更新位示图
        inodeBitmap[fileInodeNum]=0;
        blockBitmap[fileInode->blockNum]=0;

        // 更新超级块
        superBlock.blockFree+=1;
        superBlock.inodeFree+=1;
    }

    free(fileInode);
    free(parentInode);

}

void updateResource()
{
    rewind(fp);
    fwrite(&superBlock,superBlockSize,1,fp);
    fwrite(blockBitmap,blockBitmapSize,1,fp);
    fwrite(inodeBitmap,inodeBitmapSize,1,fp);
    fclose(fp);
}

void pathSet()
{
    PtrInode curInode=(PtrInode)malloc(inodeSize);
    fseek(fp,behindDataBlock+currentDir*inodeSize,SEEK_SET);
    fread(curInode,inodeSize,1,fp);
    printf("@localhost:%s#",curInode->fileName);
    free(curInode);
}

void systemInfo()
{
    printf("Sum of block number:%d\n",superBlock.blockNum);
    printf("Each block size:%d\n",superBlock.blockSize);
    printf("Free of block number:%d\n",superBlock.blockFree);
    printf("Sum of inode number:%d\n",superBlock.inodeNum);
    printf("Free of inode number:%d\n",superBlock.inodeFree);
}


int analyse(char *str)
{
    int  i;
    char temp[20];
    char *ptr_char;
    char *syscmd[]={"ls","cd","mkdir","touch","open","rm","exit","sysinfo"};
    argc = 0;
    for(i = 0, ptr_char = str; *ptr_char != '\0'; ptr_char++)
    {
        if(*ptr_char != ' ')
        {
            while(*ptr_char != ' ' && (*ptr_char != '\0'))
                temp[i++] = *ptr_char++;
            argv[argc] = (char *)malloc(i+1);
            strncpy(argv[argc], temp, i);
            argv[argc][i] = '\0';
            argc++;
            i = 0;
            if(*ptr_char == '\0')
                break;
        }
    }
    if(argc != 0)
    {
        for(i = 0; (i < 12) && strcmp(argv[0], syscmd[i]); i++);
            return i;
    }
    else
        return 12;
    return 0;
}


void command(void)
{
    char cmd[20];
    do
    {
        pathSet(); // 打印当前路径
        gets(cmd); // 输入命令
        switch(analyse(cmd))
        {
            case 0:
                list();
                break;
            case 1:
                cd(argv[1]);
                break;
            case 2:
                createFile(argv[1],1);
                break;
            case 3:
                createFile(argv[1],0);
                break;
            case 4:
                open(argv[1]);
                break;
            case 5:
                Delete(argv[1]);
                break;
            case 6:
                updateResource();
                exit(0);
                break;
            case 7:
                systemInfo();
                break;
            default:
                break;
        }
    }while(1);
}

int main(int argc,char **argv){
    openFileSystem();
    command();
    return 0;
}
