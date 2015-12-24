#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <regex>
#include "school.h"
#include "game.h"

using std::cin; using std::endl; using std::cout;
using std::string; using std::vector;
using std::ifstream; using std::ofstream;
using std::stoi;

int Game::no = 1;
int School::no = 1;

void Interface();
void Schoolrank(vector<School> &schools);
void Sportrank(vector<Game> &games);
bool WriteData(vector<Game> &game, vector<School> &schools);
bool ReadGameData(ifstream &infile, vector<Game> &games);
bool ReadSchoolData(ifstream &infile, vector<School> &schools);

int main(int argc, char *argv[]) {
    int num_sch, num_sport;
    int choose;
    vector<School> schools;
    vector<Game> games;
    ifstream infile("schools.txt");
    if (infile.is_open()) {
        ReadSchoolData(infile, schools);
        infile.close();
    } else {
        cout << "How many schools?" << endl;
        cin >> num_sch;
        schools.resize(num_sch);
    }
    infile.open("games.txt");
    if (infile.is_open()) {
        ReadGameData(infile, games);
        infile.close();
    } else {
        cout << "How many sports?" << endl;
        cin >> num_sport;
        games.resize(num_sport);
    }
    WriteData(games, schools);
    while (1) {
        Interface();
        cin >> choose;
        switch(choose) {
            case 1: 
                for (const auto &sport : games) {
                    sport.print();
                }
                WriteData(games, schools);
                break;
            case 2:
                for (const auto &sch : schools) {
                    sch.print();
                }
                WriteData(games, schools);
                break;
            case 3:
                for (const auto &sport : games) {
                    sport.print();
                }
                size_t dex;
                cout << "Witch one?" << endl;
                cin >> dex;
                games[dex-1].setscore(schools);
                WriteData(games, schools);
                break;
            case 4:
                Schoolrank(schools);
                break;
            case 5:
                Sportrank(games);
                break;
            case 0:
                exit(0);
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
    cout << "\t0. Exit" << endl;
}
void Schoolrank(vector<School> &schools) {
    vector<School> s;
    s.assign(schools.begin(), schools.end());
    stable_sort(s.begin(), s.end(),
                [] (const School &a, const School &b)
                    {return a.getscore() > b.getscore();});
    cout << "*******RANK*******" << endl;
    for (const auto o : s)
        o.print();
    cout << endl << endl;
}

void Sportrank(vector<Game> &games) {
    size_t i;
    cout << "*******RANK*******" << endl;
    for (const auto &s : games) {
        s.print();
    }
    cout << "witch one ?" << endl;
    cin >> i;
    games[i-1].printrank();
    cout << endl << endl;
}

bool WriteData(vector<Game> &game, vector<School> &schools) {
    ofstream outfile("schools.txt");
    outfile << "No:" << School::no << endl;
    for (const auto &sch : schools)
        sch.writefile(outfile);
    outfile.close();
    outfile.open("games.txt");
    outfile << "No:" << Game::no << endl;
    for (const auto &g : game)
        g.writefile(outfile);
    return !outfile.is_open();
}


bool ReadGameData(ifstream &infile, vector<Game> &games) {
    string s;
    int data, flag;
    getline(infile, s);
    if (s.find("No") != string::npos) {
        auto pos = s.find(":") + 1;
        Game::no = stoi(s.substr(pos));
    }
    games.resize(Game::no - 1);
    auto it = games.begin();
    while (getline(infile, s)) {
        auto pos = s.find(":") + 1;
        if (pos == s.size())
            continue;
        if (s.find("ID") != string::npos) {
            it->setID(stoi(s.substr(pos)));
        } else if (s.find("Winners") != string::npos) {
            it->setwinners(stoi(s.substr(pos)));
        } else if (s.find("Name") != string::npos) {
            it->setName(s.substr(pos));
        }
    }
}
bool ReadSchoolData(ifstream &infile, vector<School> &schools) {
    string s;
    int data, flag;
    getline(infile, s);
    if (s.find("No") != string::npos) {
        auto pos = s.find(":") + 1;
        School::no = stoi(s.substr(pos));
    }
    schools.resize(School::no - 1);
    auto it = schools.begin();
    while (getline(infile, s)) {
        auto pos = s.find(":") + 1;
        if (pos == s.size())
            continue;
        if (s.find("ID") != string::npos) {
            it->setID(stoi(s.substr(pos)));
        } else if (s.find("Score") != string::npos) {
            it->setscore(stoi(s.substr(pos)));
        } else if (s.find("Name") != string::npos) {
            it->setName(s.substr(pos));
        }
    }
}