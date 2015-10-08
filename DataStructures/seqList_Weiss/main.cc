#include <iostream>
#include "seqList_Weiss.cc"
using namespace std;
int main() {
    int a[] = {11, 22, 33, 44};
    int itemNumber = 4;

    Vector<int> v;
    for(int i = 0; i < itemNumber; i++)
        v.push_back(a[i]);

    cout << "The List elements are:" << endl;

    for(int i = 0; i != v.size(); ++i)
        cout << v[i] << endl;

    cout << "Print elements using iterator:" << endl;

    Vector<int>::iterator itr = v.begin();

    while(itr != v.end())
        cout << *itr++ << endl;

    system("PAUSE");
}