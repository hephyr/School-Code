#include <iostream>
using std::endl; using std::cout;
using std::cin;

template <typename T>
void foo(T a[], int n, int k);

int main (int argc, char *argv[]) {
    int a[10] = {0, 1, 5, 6, 2, 3, 4, 7, 8, 9};
    foo(a, 10, 4);
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << endl;
    }
    return 0;
}

template <typename T>
void foo(T a[], int n, int k) {
    int i = 0, j = k;
    while (i != k && j != n) {
        if (a[j] < a[i]) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            ++i;
        } else {
            ++i;
        }
    }
}