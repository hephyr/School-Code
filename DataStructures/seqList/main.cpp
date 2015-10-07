//
//  main.cpp
//  seqList
//
//  Created by Zephyr on 15/10/4.
//  Copyright © 2015年 Zephyr. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "seqList_Yan.h"

bool equal(int a, int b){
    if(a == b)
        return true;
    return false;
}

bool visit(ElemType e){
    printf(" %d", e);
    return true;
}


int main(int argc, const char * argv[]) {

//线性表的顺序表示
    SqList L;
    ElemType e;
    ElemType pre_e;
    ElemType next_e;
    
    InitList(L);
    if(ListEmpty(L))
    {
        printf("empty\n");
    }//if
    
    
    for(int i=0;i<30;i++){
        e = i+1;
        ListInsert(L, i+1, e);
    }
    
    e = 15;
    printf("15所在的位置为： %d\n", LocateElem(L, 15, equal));
    PriorElem(L, e, pre_e);
    NextElem(L, e, next_e);
    printf("e的前驱为：%d\n", pre_e);
    printf("e的后驱为：%d\n", next_e);
    
    GetElem(L, 22, e);
    printf("第22个数为：%d\n", e);
    
    printf("遍历：");
    ListTraverse(L, visit);
    printf("\n");
    printf("List length is：%d\n", ListLength(L));
    ClearList(L);
    printf("清空\n");
    printf("List length is：%d\n", ListLength(L));
    if(ListEmpty(L))
    {
        printf("empty\n");
    }
    
    
    ListInsert(L, 1, 3);
    ListInsert(L, 2, 7);
    ListInsert(L, 3, 9);
    ListInsert(L, 4, 1);
    ListInsert(L, 5, 44);
    printf("List length is：%d\n", ListLength(L));
    printf("遍历：");
    ListTraverse(L, visit);
    printf("\n");
    
    ListDelete(L, 3, e);
    printf("所删除的值为: %d\n", e);
    printf("遍历：");
    ListTraverse(L, visit);
    printf("\n");
    
    printf("xiaohui:\n");
    DestroyList(L);
    
    
    
    system("pause");
    
    
    return 0;
}
