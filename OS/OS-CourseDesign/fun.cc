#include <iostream>
#include <cstdio>
#include "inode.h"

using std::cout; using std::endl;

bool* InodeBitmap(FILE *fd);
void GetFreeInodeSpace(FILE *fd);
bool ReadInode(FILE *fd, INODE &temp);
bool WriteInode(FILE *fd, INODE &temp);
void OutputInode(INODE &temp);

// unsigned CreatInode() {
//     INode a;
//     a.i_ino = GetFreeInodeSpace();
//     a.isDir = false;
//     a.num_links = 1;
//     a.size = 1;
//     a.phisical_addr = GetFreeDataSpace(size);
//     return 0;
// }

// unsigned GetFreeDataSpace(off_t size) {         //获得数据区空闲区域
//     int fd = open("temp", O_RDWR);
//     if (fd < 0) {
//         printf("read file error");
//         exit(1);
//     }

// }

void GetFreeInodeSpace(FILE *fd) {                  //获得结点区空闲区域
    int n;
    n = fseek(fd, 21*1024, SEEK_SET);
    if (n == -1) {
        printf("seek error\n");
        exit(3);
    }
    bool *bitmap = InodeBitmap(fd);
    cout << *bitmap << endl;
    for (int i = 0; i != 10*1024/32; ++i) {
        cout << *(bitmap + i) << endl;
    }

}

bool* InodeBitmap(FILE *fd) {
    bool *bitmap = new bool[10*1024/32];
    if (bitmap == nullptr) {
        cout << "new bitmap error" << endgsl;
    }
    int n;
    int size = 1024 * 10;               //结点区多少字节
    n = fseek(fd, 21*1024, SEEK_SET);
    if (n == -1) {
        printf("seek error\n");
        exit(3);
    }
    unsigned temp[4];
    int flag;
    for (int i = 0; i*32 < size; ++i) {
        flag = 0;
        n = fread(&temp, sizeof(unsigned), sizeof(unsigned)*4, fd);
        for (int j = 0; j != 4; ++j) {
            if (temp[j] != 0) {
                flag = 1;
            }
        }
        if (flag != 0)
            *(bitmap + i) = 1;
        else
            *(bitmap + i) = 0;
    }
    cout << "bingo" << endl;
    return bitmap;
}

bool ReadInode(FILE *fd, INODE &temp) {
    int n;
    n = fseek(fd, (21*1024) + (temp.i_ino*32), SEEK_SET);
    if (n == -1) {
        printf("seek error\n");
        exit(3);
    }
    n = fread(&(temp.i_ino), sizeof(unsigned), sizeof(unsigned), fd);
    if (n < 0) {
        printf("read error\n");
        exit(1);
    }
    n = fread(&(temp.isDir), sizeof(bool), sizeof(bool), fd);
    if (n < 0) {
        printf("read error\n");
        exit(1);
    }
    n = fread(&(temp.num_links), sizeof(nlink_t), sizeof(nlink_t), fd);
    if (n < 0) {
        printf("read error\n");
        exit(1);
    }
    n = fread(&(temp.size), sizeof(off_t), sizeof(off_t), fd);
    if (n < 0) {
        printf("read error\n");
        exit(1);
    }
    n = fread(&(temp.phisical_addr), sizeof(unsigned), sizeof(unsigned), fd);
    if (n < 0) {
        printf("read error\n");
        exit(1);
    }
    return true;
}
bool WriteInode(FILE *fd, INODE &temp) {
    int n;
    n = fseek(fd, (21*1024) + (temp.i_ino*32), SEEK_SET);    //找到要写入的结点区
    if (n == -1) {
        printf("seek error\n");
        exit(3);
    }
    n = fwrite(&(temp.i_ino), sizeof(unsigned), sizeof(unsigned), fd);
    if (n < 0) {
        printf("write error1\n");
        exit(2);
    }
    n = fwrite(&(temp.isDir), sizeof(bool), sizeof(bool), fd);
    if (n < 0) {
        printf("write error2\n");
        exit(2);
    }
    n = fwrite(&(temp.num_links), sizeof(nlink_t), sizeof(nlink_t), fd);
    if (n < 0) {
        printf("write error3\n");
        exit(2);
    }
    n = fwrite(&(temp.size), sizeof(off_t), sizeof(off_t), fd);
    if (n < 0) {
        printf("write error4\n");
        exit(2);
    }
    n = fwrite(&(temp.phisical_addr), sizeof(unsigned), sizeof(unsigned), fd);
    if (n < 0) {
        printf("write error5\n");
        exit(2);
    }
    return true;
}

void OutputInode(INODE &temp) {
    printf("i_ino: %d\n", temp.i_ino);
    printf("isDir: %d\n", temp.isDir);
    printf("num_links: %d\n", temp.num_links);
    printf("size: %lld\n", temp.size);
    printf("phisical_addr: %d\n", temp.phisical_addr);
}

int main() {
    INODE a;
    a.i_ino = 1;
    // a.isDir = false;
    // a.num_links = 1;
    // a.size = 1;
    // a.phisical_addr = 12;
    FILE *fd;
    fd = fopen("temp", "rb+");           //Read/Write file only work in "r+"
    // WriteInode(fd, a);
    // ReadInode(fd, a);
    // OutputInode(a);
    GetFreeInodeSpace(fd);
    return 0;
}