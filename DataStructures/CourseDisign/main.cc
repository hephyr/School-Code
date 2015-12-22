#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "school.h"
#include "game.h"

using std::cin; using std::endl; using std::cout;
using std::string; using std::vector;


int Game::no = 1;
int School::no = 1;

void Interface();

int main(int argc, char *argv[]) {
    int num_sch, num_sport;
    int choose;
    vector<School> schools;
    vector<Game> games;
	cout << "How many schools?" << endl;
    cin >> num_sch;
    schools.resize(num_sch);
    cout << "How many sports?" << endl;
    cin >> num_sport;
    games.resize(num_sport);
    while (1) {
        Interface();
        cin >> choose;
        switch(choose) {
            case 1: 
                for (auto &sport : games) {
                    sport.print();
                }
                break;
            case 2:
                for (auto &sch : schools) {
                    sch.print();
                }
            case 3:
                for (auto &sport : games) {
                    sport.print();
                }
                size_t dex;
                cout << "Witch one?" << endl;
                cin >> dex;
                games[dex-1].setscore(schools);
                break;
            default : ;
        }
    }
    return 0;
}

void Interface() {
    cout << "1. Sports" << endl;
    cout << "2. Schools" << endl;
    cout << "3. Fill Score" << endl;
    cout << "4. School Rank" << endl;
    cout << "5. The Sport Score" << endl;
}