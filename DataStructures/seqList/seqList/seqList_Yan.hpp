//
//  seqList_Yan.hpp
//  seqList
//
//  Created by Zephyr on 15/10/4.
//  Copyright © 2015年 Zephyr. All rights reserved.
//

#ifndef seqList_Yan_hpp
#define seqList_Yan_hpp
#define ElementType int
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

List InitList();
void Destroy(List L);
void ClearList(List L);
bool ListEmpty(List L);
int ListLength(List L);
ElementType GetElem(List L, int i);
Position LocateElem(List L, ElementType e);
Position PriorElem(List L, ElementType cur_e);
Position NextElem(List L, ElementType cur_e);
void ListInsert(List L, int i, ElementType e);
ElementType Delete(List L, int i);

#endif /* seqList_Yan_hpp */
