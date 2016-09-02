#ifndef _DIRITEM_H_
#define _DIRITEM_H_

// Dir item structure 
// Every dir has 128 dir items

#define MAX_NAME_LEN

struct DirItem
{
    unsigned int num_inode;
    char file_name[MAX_NAME_LEN];
};

#endif