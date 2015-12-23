#include <iostream>
#include <vector>
#include "school.h"
using std::cout; using std::endl;
int main() {
    std::vector<int> a{1, 2, 3};
    std::vector<int> b;
    b.assign(a.begin(), a.end());
    b[1] = 6;
    for (auto c : b)
        cout << c << endl;
    for (auto c : a)
        cout << c << endl;
    return 0;
}