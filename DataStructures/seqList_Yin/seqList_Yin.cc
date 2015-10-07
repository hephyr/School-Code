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
#include "linearList.h"
//#include "seqList_Yin.h"
using namespace std;

const int defaultSize = 100;

template<class T>
class SeqList:public LinearList<T> {
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
    bool IsEmpty() const;
    bool IsFull() const;
    void input();
    void output();
    //SeqList<T> operator=(SeqList<T>& L);
 protected:
    T *data;
    int maxSize;
    int last;
    void reSize(int newSize);
};



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
template <class T>
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
template <class T>
void SeqList<T>::reSize(int newSize) {
    if (newSize <= 0) {
        cerr << "无效的数组大小" << endl;
        return ;
    }
    if (newSize != maxSize) {
        T* newarray = new T[newSize];
        if (newarray == NULL) {
            cerr << "储存分配错误" << endl;
            exit(1);
        }
        int n = last + 1;
        T* srcptr = data;
        T* destptr = newarray;
        while (n--)
            *destptr++ = *srcptr++;
        delete []data;
        data = newarray;
        maxSize = newSize;
    }
}
template <class T>
int SeqList<T>::Size() const {
    return maxSize;
}
template <class T>
inline int SeqList<T>::Length() const {
    return last + 1;
}
template <class T>
int SeqList<T>::Search(T& x) const {
    for (int i = 0; i <= last; i++)
        if (data[i] == x)
            return i+1;
    return 0;
}
template <class T>
inline int SeqList<T>::Locate(int i) const {
    if (i >= 1 && i <= last + 1)
        return i;
    else
        return 0;
}
template <class T>
bool SeqList<T>::getData(int i, T& x) const {
    if (i>0 && i <= last + 1){
        x = data[i-1];
        return true;
    }
    return false;
}
template <class T>
void SeqList<T>::setData(int i, T& x) {
    if (i>0 && i <= last + 1)
        data[i-1] = x;
}
template <class T>
bool SeqList<T>::Insert(int i, T& x) {
    if (last == maxSize -1) return false;
    if (i < 0 || i > last + 1) return false;
    for (int j = last; j >= i; j--)
        data[j+1] = data[j];
    data[i] = x;
    last++;
    return true;
}
template <class T>
bool SeqList<T>::Remove(int i, T& x) {
    if (last == -1) return false;
    if (i < 1 || i > last + 1) return false;
    x = data[i-1];
    for (int j = i; j <= last; j++)
        data[j-1] = data[j];
    last--;
    return true;
}
template <class T>
inline bool SeqList<T>::IsEmpty() const {
    return (last == -1) ? true : false;
}
template <class T>
inline bool SeqList<T>::IsFull() const {
    return (last == maxSize -1) ? true : false;
}
template <class T>
void SeqList<T>::input() {
    cout << "开始建立顺序表，请输入表中元素个数" << endl;
    while (1) {
        cin >> last;
        if (last <= maxSize - 1)
            break;
        cout << "表元素个数输入有误，范围不能超过" << maxSize - 1 << ":";
        for (int i = 0; i <= last; i++) {
            cin >> data[i];
            cout << i+1 << endl;
        }
    }
}
template <class T>
void SeqList<T>::output() {
    cout << "顺序表当前元素最后位置为:" << last << endl;
    for (int i; i <= last; i++)
        cout << "#" << i+1 << ":" << data[i] << endl;
}
//template <class T>
//SeqList<T> SeqList<T>::operator=(SeqList<T>& L) {
//    last = L.last;
//    maxSize = L.maxSize;
//    for (int i = 0; i <= last; i++) {
//        data[i] = L.data[i];
//    }
//}