//
//  seqList_Yan.hpp
//  seqList
//
//  Created by Zephyr on 15/10/4.
//  Copyright © 2015年 Zephyr. All rights reserved.
//

#ifndef seqList_Yan_h
#define seqList_Yan_h
#define ElementType int

#include <stdio.h>
#include "Common.h"


#define ElemType int

#define LIST_INIT_SIZE	100	//线性表存储空间的初始分配量
#define LISTINCREMENT	10	//线性表存储空间的分配增量

typedef struct{
    ElemType* elem;	//存储空间基址
    int length;			//当前长度
    int listsize;		//当前分配的存储容量（以sizeof(ElemType)为单位）
} SqList;

//基本操作:增删查改，始判清长

Status InitList(SqList &L);
//操作结果：构造一个空的线性表L。


Status DestroyList(SqList &L);
//初始条件：线性表L已存在。
//操作结果：销毁线性表L。


Status ClearList(SqList &L);
//初始条件：线性表L已存在。
//操作结果：将L重置为空表。


bool ListEmpty(SqList L);
//初始条件：线性表L已存在。
//操作结果：若L为空表，则返回TRUE，否则返回FALSE。


int ListLength(SqList L);
//初始条件：线性表L已存在。
//操作结果：返回L中数据元素的个数。


Status GetElem(SqList L, int i, ElemType &e);
//初始条件：线性表L已存在，1<=i<=ListLength(L)。
//操作结果：用e返回L中第i个数据元素的值。


int LocateElem(SqList L, int e, bool (*equal)(ElemType, ElemType));
//初始条件：线性表L已存在，compare()是数据元素判定函数。
//返回L中第一个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0.

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e);
//初始条件：线性表L已存在。
//操作结果：若cur_e是L中的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义。

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e);
//初始条件：线性表L已存在。
//操作结果：若cur_e是L中的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义。

Status ListInsert(SqList &L, int i, ElemType e);
//初始条件：线性表L已存在，1<=i<=ListLength(L)+1.
//操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1.

Status ListDelete(SqList &L, int i, ElemType &e);
//初始条件：线性表L已存在且非空，1<=i<=ListLength(L).
//操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1.

Status ListTraverse(SqList L, bool (*visit)(ElemType));
//初始条件：线性表L已存在
//操作结果：依次对L的每个元素调用函数visit().一旦visit()失败,则操作失败。

#endif /* seqList_Yan_h */
