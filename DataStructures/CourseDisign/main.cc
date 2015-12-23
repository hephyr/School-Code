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
void Schoolrank(vector<School> &schools);

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
            case 4:
                Schoolrank(schools);
            default : ;
        }
    }
    return 0;
}

void Interface() {
    cout << "*******WELCOME*******" << endl;
    cout << "\t1. Sports" << endl;
    cout << "\t2. Schools" << endl;
    cout << "\t3. Fill Score" << endl;
    cout << "\t4. School Rank" << endl;
    cout << "\t5. The Sport Score" << endl;
}
void Schoolrank(vector<School> &schools) {
    vector<School> s;
    s.assign(schools.begin(), schools.end());
    stable_sort(s.begin(), s.end(),
                [] (const School &a, const School &b)
                    {return a.getscore() > b.getscore();});
    cout << "*******RANK*******" << endl;
    for (auto o : s)
        o.print();
    cout << endl << endl;
}