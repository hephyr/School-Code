#ifndef _INODE_H_
#define _INODE_H_

//Index Node(FCB) structure

unsigned INODE_NUM = 0;

typedef struct INode
{
    unsigned i_ino;     //inode_NO
    bool isDir;
    nlink_t num_links;
    off_t size; // off_t = long int | size = file_size or dir_length
    unsigned phisical_addr;
    // sum 19 Bytcd 
} INODE;

#endif