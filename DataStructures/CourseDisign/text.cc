#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <string>
#include "school.h"
using std::cout; using std::endl;
using std::vector; using std::string;
using std::regex;
int main() {
	string s;
	std::ifstream infile("schools.txt");
	int i = 1;
	while (getline(infile, s)) {
		cout << i++;
		auto pos = s.find(":") + 1;
        if (pos == s.size()) {
        	cout << "None" << endl;
            continue;
        }
        cout << endl;
	}
    return 0;
}