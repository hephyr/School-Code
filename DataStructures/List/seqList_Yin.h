//
//
//
//	seqList_Yin.h
//	Created by Hefeng Xu
//	Source Code Editor Sublimbe Text
//	GNU Compiler Collection
//	System Mac OS X 10.10
//

#ifndef SEQLIST_H
#define SEQLIST_H
#include <iostream>
#include <cstdlib>
#include <linearList.h>

const int defaultSize = 100;

template<class T>
class SeqList:public LinearList<T> {
protected:
	T *data;
	int maxSize;
	int last;
	void reSize(int newSize);
public:
	SeqList(int sz = defaultSize);
	SeqList(SeqList<T>& L);
	~SeqList();
	int Size() const;
	int Length() const;
	int Search(T& x) const;
	int Locate(int i) const;
	bool getData(int i, T& x) const;
	void setData(int i, T& x);
	bool Insert(int i, T& x);
	bool Remove(int i, T& x);
	bool IsEmpty();
	bool IsFull();
	void input();
	void output();
	SeqList<T> operator=(SeqList<T>& L);
};

#endif //SEQLIST_H