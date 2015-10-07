//
//  seqList_Yan.cpp
//  seqList
//
//  Created by Zephyr on 15/10/4.
//  Copyright © 2015年 Zephyr. All rights reserved.
//

#include "seqList_Yan.h"
#include <stdlib.h>

Status InitList(SqList &L){
    //操作结果：构造一个空的线性表L。
    
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L.elem) exit(OVERFLOW);	//存储分配失败
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}//InitList

Status DestroyList(SqList &L){
    //操作结果：销毁线性表L。
    
    free(L.elem);
    L.elem=NULL;
    L.length=0;
    L.listsize=0;
    
    return OK;
}

Status ClearList(SqList &L) {
    //操作结果：将L重置为空表。
    L.length = 0;
    return OK;
}

bool ListEmpty(SqList L){
    //操作结果：若L为空表，则返回TRUE，否则返回FALSE。
    
    if(0 == L.length)
        return true;
    else
        return false;
}

int ListLength(SqList L){
    //操作结果：返回L中数据元素的个数。
    
    return L.length;
}

Status GetElem(SqList L, int i, ElemType &e){
    //1<=i<=ListLength(L)。
    //操作结果：用e返回L中第i个数据元素的值。
    
    if(i < 1  ||  i>=L.length) return ERROR;
    e = L.elem[i-1];
    return OK;
}

int LocateElem(SqList L, ElemType e, bool (*equal)(ElemType, ElemType)){
    //compare()是数据元素判定函数。
    //返回L中第一个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0.
    
    int i = 1;
    ElemType* p = L.elem;
    while(i <= L.length  &&  !(*equal)(*p++, e))
        ++i;
    if(i <= L.length)
        return i;
    
    else return 0;
}

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e){
    //操作结果：若cur_e是L中的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义。
    
    int i=1;
    while(i <= L.length  && !(cur_e==L.elem[i-1])) ++i;
    if(i<2 || i>L.length)
        return ERROR;
    pre_e = L.elem[i-2];
    return OK;
}

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e){
    //操作结果：若cur_e是L中的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义。
    
    int i=1;
    while(i <= L.length  && !(cur_e==L.elem[i-1])) ++i;
    if(i<2 || i>L.length)
        return ERROR;
    next_e = L.elem[i];
    return OK;
}

Status ListInsert(SqList &L, int i, ElemType e){
    //1<=i<=ListLength(L)+1.
    //操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1.
    
    if(i < 1 || i>L.length+1) return ERROR;	//i值不合法
    if(L.length >= L.listsize) {
        ElemType * newbase = (ElemType *)realloc(L.elem, (L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)
            exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    ElemType * q = &(L.elem[i-1]);	//q为插入位置
    ElemType * p;
    for(p=&(L.elem[L.length-1]);p>=q;--p)
        *(p+1) = *p;	//右移
    
    *q = e;
    ++L.length;
    return OK;
}//ListInsert

Status ListDelete(SqList &L, int i, ElemType &e){
    //1<=i<=ListLength(L).
    //操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1.
    
    if(i<1 || i>L.length) return ERROR;
    ElemType* p = &(L.elem[i-1]);
    e = *p;
    ElemType* q = L.elem + L.length - 1;
    for(++p;p<=q;++p) *(p-1) = *p;
    --L.length;
    return OK;
}

Status ListTraverse(SqList L, bool (*visit)(ElemType)){
    //操作结果：依次对L的每个元素调用函数visit().一旦visit()失败,则操作失败。
    
    int i=1;
    ElemType* p = L.elem;
    while(i <= L.length  &&  (*visit)(*p++)) ++i;
    return OK;
}