#include <iostream>
#include <vector>
#include "Array.h"
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main() {
    Array a(4,4);
    cout << "\n\n";
    a.print();
    cout << "\n\n";
    a.Warshall();
    a.print();
    return 0;
}