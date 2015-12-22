#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "school.h"
#include "game.h"

using std::cin; using std::endl; using std::cout;
using std::string; using std::vector; using std::list;


int Game::no = 1;
int School::no = 1;

int main(int argc, char *argv[]) {
    int num_sch;
    vector<School> schools;
	cout << "How many schools?" << endl;
    cin >> num_sch;
    schools.resize(num_sch);
    return 0;
}