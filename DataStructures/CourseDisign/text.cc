#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <string>
#include "school.h"
using std::cout; using std::endl;
using std::vector; using std::string;
using std::regex; using std::npos;
int main() {
	// string pattern("Score:(.*?)\n");
	// regex r(pattern);
	// std::smatch results;
	std::ifstream infile("schools.txt");
	string s;
	while (getline(infile, s)) {
		auto pos = s.find(":") + 1;
		if (pos == s.size())
			continue;
		if (s.find("ID") != npos) {

		} else if (s.find("Winners") != npos) {

		} else if (s.find("Name") != npos) {

		} else if (s.find("No") != npos) {
			
		}
		int a = std::stoi(s.substr(s.find(":") + 1));

		cout << a << endl;
	}
	infile.close();
    return 0;
}