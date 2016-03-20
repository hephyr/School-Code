#include <iostream>
using std::endl; using std::cout;
using std::cin;

template <typename T> 
void exchange(T a[], int left, int right, int k);

template <typename T>
void sp(T a[], int left, int right, int amount);


int main(int argc, char *argv[]) {
    int a[5] = {1, 2, 3, 4, 5};
    exchange(a, 0, 4, 2);
    for (int i = 0; i < 5; ++i) {
        cout << a[i] << endl;
    }
    return 0;
}

template <typename T>
void exchange(T a[], int left, int right, int k) {
    int middle = (left + right) / 2;
    if (k > middle) {
        sp(a, left, k, right - k);
        exchange(a, left + right - k, right, k);
    } else if (k < middle) {
        sp(a, left, left + right -k, k - left);
        exchange(a, k, right, right - k);
    } else {
        sp(a, left, k, (right - left) / 2);
    }
}

template <typename T>
void sp(T a[], int start_a, int start_b, int amount) {
    int temp;
    for (int i = 0; i < amount; ++ i) {
        temp = a[start_a + i];
        a[start_a + i] = a[start_b + i];
        a[start_b + i] = temp;
    }
}