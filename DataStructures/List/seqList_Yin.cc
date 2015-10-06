//
//
//
//	seqList_Yin.cc
//	Created by Hefeng Xu
//	Source Code Editor Sublimbe Text
//	GNU Compiler Collection
//	System Mac OS X 10.10
//

#include <iostream>
#include <cstdlib>
#include "seqList.h"
template <class T>
SeqList<T>::SeqList(int sz) {
	if (sz > 0){
		maxSize = sz;
		last = -1;
		data = new T[maxSize];
		if (data == NULL) {
			cerr << "储存分配错误!" << endl;
			exit(1);
		}
	}
}
SeqList<T>::SeqList(SeqList<T>& L) {
	maxSize = L.Size();
	last = L.Length() - 1;
	T value;
	data = new T[maxSize];
	if (data == NULL) {
		cerr << "储存分配错误!" << endl;
		exit(1);
	}
	for (int i = 1; i <= last +1; i++) {
		L.getData(i, value);
		data[i-1] = value;
	}
}
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