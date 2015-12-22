#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "school.h"
#include "game.h"

Game::no = 1;
School::no = 1;
using std::cin; using std::endl; using std::cout;
using std::string; using std::vector; using std::list;

int main(int argc, char *argv[]) {
	list<School> S(10);
    for (auto &school : S) {
        cout << school.getID() << endl;
    }
    list<Game> G(10);
    for (auto &game : G)
    	game.getscore(S);
    return 0;
}