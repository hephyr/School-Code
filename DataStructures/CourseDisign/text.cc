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
	string pattern("Score:(.*?)\n");
	regex r(pattern);
	std::smatch results;
	std::ifstream infile("games.txt");
	string hello;
	infile >> hello;
	cout << hello << endl;
	if (std::regex_search(hello, results, r))
		cout << results.str() << endl;
	infile.close();
    return 0;
}