// 链队列.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include "LinkQueue.h"
#include <stdlib.h>
#include <time.h>
#include <iomanip>
int main(int argc, char *argv[]) {

    LinkedQueue<int> A, B;
    int n, x, y, i;
    srand((unsigned)time(NULL));
    for(i = 1; i <= 20; i++) {
        n = rand() % 100;
        if(n % 2 == 0)
            A.EnQueue(n);
        else
            B.EnQueue(n);
    }
    A.output();
    B.output();

    while(!A.IsEmpty() && !B.IsEmpty()) {
        A.DeQueue(x);
        B.DeQueue(y);
        cout << setw(5) << x << setw(5) << y << endl;
    }
    return 0;
}
