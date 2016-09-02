#ifndef _SBLOCK_H_
#define _SBLOCK_H_

//Super Block structure

struct SBlock
{
    unsigned long FS_size; // the whole FileSystem size
    unsigned int num_free_blocks;
    /*
    TODO:
        1.文件系统上可用的空闲块表
        2.空闲块表中下一个空闲块的下标
        3.索引结点表的大小
        4.文件系统中空闲索引结点号表
        5.文件系统中空闲索引结点的数目
        6.空闲索引结点表中下一个空闲索引结点的下标
        7.栈长度
        8.成组链接?? or Bitmap??
    */
};

#endif