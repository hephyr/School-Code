#include <iostream>
using std::endl; using std::cout;
using std::cin;

template <typename T>
void exchange(T a[], int left, int right, int k);

template <typename T>
void sp(T a[], int left, int right, int amount);


int main(int argc, char *argv[]) {
    int a[5] = {1, 2, 3, 4, 5};
    exchange(a, 0, 4, 5);
    for (int i = 0; i < 5; ++i) {
        cout << a[i] << endl;
    }
    system("pause");
    return 0;
}

template <typename T>
void exchange(T a[], int left, int right, int k) {
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
void sp(T a[], int start_a, int start_b, int amount) {
    int temp;
    for (int i = 0; i < amount; ++i) {
        temp = a[start_a + i];
        a[start_a + i] = a[start_b + i];
        a[start_b + i] = temp;
    }
}