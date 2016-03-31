#include <iostream>
#include <vector>
#include <fstream>

using std::cin; using std::endl;
using std::cout; using std::vector;
using std::ifstream;

template <class T>
int BinarySearch(vector<T>& a, const T& x, int& left, int& right);

int main(int argc, char *argv[]) {
    vector<int> a;
    ifstream f;
    f.open("array.txt");
    int value;
    while (f >> value) {
        a.push_back(value);
    }
    int x;
    cout << "input the number" << endl;
    cin >> x;
    int left = 0, right = a.size() - 1;
    int find = BinarySearch(a, x, left, right);
    if (find != -1)
        cout << "Ha Ha Ha I find it" << endl;
    else {
        cout << "Not find" << endl;
        if (right < 0) {
            cout << "the closest bigger number is " << a[left] << endl;
            cout << "no smaller number than it" << endl;
        }
        else if (left >= a.size()) {
            cout << "the closest smaller number is " << a[right] << endl;
            cout << "no bigger number than it" << endl;
        } else {
            cout << " the closest smaller number is " << a[right] << endl;
            cout << "the closest bigger number is " << a[left] << endl;
        }
    }
    return 0;
}

template <class T>
int BinarySearch(vector<T>& a, const T& x, int& left, int& right) {
    while (left <= right) {
        int middle = (left + right) / 2;
        if (x == a[middle]) return middle;
        if (x > a[middle])
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}