#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::endl;
using std::cout; using std::vector;
template <class T>
int BinarySearch(vector<T>& a, const T& x, int& left, int& right);
int main() {
    vector<int> a = {1, 2, 3, 4, 5, 7, 8};
    int x;
    cin >> x;
    int left = 0, right = a.size() - 1;
    int find = BinarySearch(a, x, left, right);
    if (find != -1)
        cout << "Ha Ha Ha I find it" << endl;
    else {
        cout << "55555 Not find" << endl;
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