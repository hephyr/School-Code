#include <iostream>
#include <cstdlib>
#include "linearList.h"
using namespace std;
int main() {
	SeqList<int> sl;
	sl.input();
	int data = 20;
	int i = sl.Length();
	cout << "Insert data" << endl;
	if (sl.Insert(i, data)) {
		cout << "Insert successful" << endl;
	} else {
		cout << "Insert failed" << endl;
	}
	sl.output();
	cout << "Change data" << endl;
	data = 40;
	sl.setData(i, data);
	sl.output();
	cout << "Delete data" << endl;
	if (sl.Remove(i, data)) {
		cout << "Remove successful" << endl;
	} else {
		cout << "Remove failed" << endl;
	}
	sl.output();

	system("pause");
	return 0;
}