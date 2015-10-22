#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
int main() {
	list<string> strL;
    vector<int> v;
    string str;
    cout << "Please input the list element" << endl;
    while (cin >> str)
        strL.push_back(str);
    cin.clear();
    int inputNum;
    cout << "Please input the vector element." << endl;
    while (cin >> inputNum)
        v.push_back(inputNum);
    for (auto val : v) {
        auto itrL = strL.begin();
        for (int i = 0; i != val-1; ++i, ++itrL);
        cout << *itrL << endl;
    }
	return 0;
}