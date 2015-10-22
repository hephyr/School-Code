#ifndef _LIST_H_
#define _LIST_H_

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;
int IsEmpty(List L);
int IsLast(Position P);
Position CreatEmptyList();
Position Find(int x, List L);
Position FindPrevious(int x, List L);
Position FindLast(List L);
void Delete(int x, List L);
void Insert(int x, List L, Position P);
void Print(List L);

#endif //_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "List.h"
struct Node{
	int x;
	Position Next;
};

int main() {
	int n;
	int i = 1;
	List L;
	L = CreatEmptyList();
	while(1){
		printf("1	插入\n");
		printf("2 	删除\n");
		scanf("%d", &n);
		switch(n){
			case 1 : Insert(i++, L, FindLast(L)); Print(L); break;
			case 2 : Delete(--i, L); Print(L); break;
		}
	}
	return 0;
}

Position CreatEmptyList() {
	List L;
	L = (List)malloc(sizeof(struct Node));
	if (L == NULL) {
		exit(2);
	}
	L->x = 0;
	L->Next = NULL;
	return L;
}
int IsEmpty(List L) {
	return L == NULL;
}
int IsLast(Position P) {
	return P->Next == NULL;
}
Position Find(int x, List L) {
	Position P;
	P = L->Next;
	while(P != NULL && P->x != x)
		P = P->Next;
	return P;
}
Position FindLast(List L) {
	Position P;
	P = L;
	while (P->Next)
		P = P->Next;
	return P;
}
void Delete(int x, List L) {
	Position P, Temp;
	P = FindPrevious(x, L);
	if (!IsLast(P)){
		Temp = P->Next;
		P->Next = Temp->Next;
		free(Temp);
	}
	// else if (P->x == x){
	// 	printf("\nHahahaha\n");
	// 	Temp = P;
	// 	P = NULL;
	// 	free(Temp);
	// }
}
Position FindPrevious(int x, List L) {			//与Find不同   该函数是找出前驱元		从而完成Delete
	Position P;
	P = L;
	while(P->Next != NULL && P->Next->x != x)
		P = P->Next;
	return P;
}
void Insert(int x, List L, Position P) {
	Position Temp;
	Temp =(Position)malloc(sizeof(struct Node));
	if (!Temp)
		exit(2);
	Temp->x = x;
	Temp->Next = P->Next;
	P->Next = Temp;
}
void Print(List L) {
	Position P;
	P = L->Next;
	while (P != NULL) {
		printf("%d->", P->x);
		P = P->Next;
	}
	printf("\n");
}