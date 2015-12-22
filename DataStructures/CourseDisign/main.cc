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

void Interface();

int main(int argc, char *argv[]) {
    int num_sch, num_sport;
    vector<School> schools;
    list<Game> games;
	cout << "How many schools?" << endl;
    cin >> num_sch;
    schools.resize(num_sch);
    cout << "How many sports?" << endl;
    cin >> num_sport;
    games.resize(num_sport);
    Interface();
    return 0;
}

void Interface() {
    cout << "1. Sports" << endl;
    cout << "2. Schools" << endl;
    cout << "3. School Rank" << endl;
    cout << "4. The Sport Score" << endl;
}