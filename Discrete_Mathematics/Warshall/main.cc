#include <iostream>
#include <vector>
#include <fstream>
#include "Array.h"
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(int argc, char * argv[]) {
	std::ifstream infile(argv[1]);
	cout << "Confirm the data stored in \'infile\'" << endl;
	cout << "How many rows?" << endl;
	int i;
	cin >> i;
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