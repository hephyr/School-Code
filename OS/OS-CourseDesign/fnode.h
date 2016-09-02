#ifndef _FNODE_H_
#define _FNODE_H_

typedef struct Fnode
{
	char* fsname; //File system name
	int fssize;
	int empty; //文件系统空闲盘块大小
	int blockstack; //空闲盘块栈
    //bitmap? 
    bool free_inode[320]; //inode区被占用情况
}Fnode;

#endif