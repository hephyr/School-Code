#include <iostream>
#include <vector>
#include <fstream>
#include "Array.h"
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char * argv[]) {
    char file[] = "infile";
	std::ifstream infile(file);
	cout << "Confirm the data stored in \'infile\'" << endl;
	int i = numline(file);
    Array a(i, i);
    a.Write(infile);
    cout << "\n\n";
    a.print();
    cout << "\n\n";
    do {
    	a.Warshall();
    	--i;
    } while (i == 0);
    a.print();
    return 0;
}