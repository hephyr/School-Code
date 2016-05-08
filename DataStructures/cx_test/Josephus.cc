#include <iostream>
#include <cstdlib>
#include <ctime>
#include "circular_queue.h"
using std::cout; using std::endl;


void foo(LinkList &l) {
    if (l.empty()) {
        std::cerr << "The list is empty" << endl;
        exit(1);
    }
    while (!l.one_node()) {
        srand( (unsigned)time( NULL ) );
        int n = rand() % 100;
        l.b_delete(n);
    }
}
int main() {
    LinkList l(10);
    cout << "The circular queue: ";
    l.show();
    foo(l);
    cout << "\n" << "After delete, remaining elements: ";
    l.show();
    cout << endl;
    return 0;
}