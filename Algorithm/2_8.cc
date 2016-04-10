#include <iostream>
#include <fstream>
#include <vector>

using std::endl; using std::cout;
using std::cin; using std::ifstream;
using std::vector;


template <typename T>
void exchange(vector<T> &v, int left, int right, int k);

template <typename T>
void sp(vector<T> &v, int left, int right, int amount);


int main(int argc, char *argv[]) {
    ifstream file;
    file.open("array.txt");
    vector<int> a;
    int value;
    while (file >> value) {
        a.push_back(value);
    }
    exchange(a, 0, a.size() - 1, 2);
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << endl;
    }
    return 0;
}

template <typename T>
void exchange(vector<T> &a, int left, int right, int k) {
    if (left >= right || k > right)
        return;
    if (k - left < right - k + 1) {
        sp(a, left, left + right - k + 1, k - left);
        exchange(a, left, left + right - k, left + right - k);
    } else if (k - left > right - k + 1) {
        sp(a, left, k, right - k + 1);
        exchange(a, left + right - k + 1, right, k);
    } else {
        sp(a, left, k, right - k + 1);
    }
}

template <typename T>
void sp(vector<T> &a, int start_a, int start_b, int amount) {
    int temp;
    for (int i = 0; i < amount; ++i) {
        temp = a[start_a + i];
        a[start_a + i] = a[start_b + i];
        a[start_b + i] = temp;
    }
}