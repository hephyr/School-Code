#ifndef _DIRECTORY_H_
#define _DIRECTORY_H_

typedef struct Directory {
	char filename[14]; //文件名14字节
	short node_id; //目录Node id
	char parentfilename[14]; //父目录名
	short parent_node_id; //父目录Node id
}Directory;

#endif