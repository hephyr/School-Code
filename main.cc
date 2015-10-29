#include <iostream>
#include <vector>
#include "Array.h"
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main() {
    Array a(4,4);
    a.print();
    a.Warshall();
    a.print();
    return 0;
}