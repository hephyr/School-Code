#include <iostream>
#include <iomanip>
#include <fstream>
#include "sblock.h"
#include "inode.h"
#include "fnode.h"

using namesapce std;

void init() {
	fp = open("FILE_SYSTEM", "r+b");
	if (!fp) {
		FILE *fp1 = fopen("FILE_SYSTEM", "w+b");
		Fnode *f_system = (Fnode *)filesystem;
		f_system->fsname = "UJN_FILE_SYSTEM";
		f_system->fssize = 20*1024*1024;
		f_system->empty = 20*1024*1024;
	}
	/*
	TODO:
		bitmap?
		stack?
	*/
	out << file_system->fname 
	    << file_system->ffsize 
	    << file_system->empty;
	out.close();
}

int mkdir(string dirname) {
	int same = samefile(dirname);
	if (same == -1) {
		cout << "禁止创建同名目录" << endl;
		return -1;
	}
	int inodeid = get_inode();
	if(inodeid >= 0) {
		cout << "成功分配到 " << inodeid << endl;          
	} else {
		cout << "inode节点已经用完" << endl;
		return -1; 
	}
	int block_number = get_block();
	if(block_number >= 0) {
		cout << "被分配到第 " << block_number << endl; 
	} else {
		cout << "文件系统已经分配满" << endl;
		return -1;
	}

	

}

int samefile() {}
int get_inode() {}
int get_block() {}

int main(int argc, char const *argv[])
{
	init();
	return 0;
}


