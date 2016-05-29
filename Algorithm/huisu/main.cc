#include <iostream>
#include "nQueen.h"
using std::cin;
using std::cout; using std::endl;

long nQueen(int n);

int main() {
    int n;
    cout << "How many\n>";
    cin >> n;
    long sum = nQueen(n);
    cout << "Sum = " << sum << endl;
    return 0;
}
long nQueen(int n) {
    Queen X(n);
    int *p = new int[n+1];
    for (int i = 0; i <= n; ++i)
        p[i] = 0;
    X.setPtr(p);
    X.Backtrack(1);
    delete []p;
    return X.getSum();
}