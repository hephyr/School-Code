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
using std::ofstream; using std::ifstream;
using std::stoi;


int Game::no = 1;
int School::no = 1;
void Interface();
void Schoolrank(vector<School> &schools);
void Sportrank(vector<Game> &games);
bool WriteData(vector<Game> &game, vector<School> &schools);
void Interface_in(vector<School> &schools, vector<Game> &games);
void Interface_out(vector<School> &schools, vector<Game> &games);
void Interface_md(vector<School> &schools, vector<Game> &games);
void Menrank(vector<School> &schools);
void Womenrank(vector<School> &schools);
void ReadGameData(ifstream &infile, vector<Game> &games);
void ReadSchoolData(ifstream &infile, vector<School> &schools);
void ResetID(vector<School> &schools);
void ResetID(vector<Game> &games);

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
        switch (choose) {
            case 1:Interface_in(schools, games);
                break;
            case 2:Interface_out(schools, games);
                break;
            case 3:Interface_md(schools, games);
                break;
            case 0:
                exit(0);
            default:cout << "Error!Input again!" << endl;
        }
    }
    return 0;
}

void Interface() {
    cout << "***********WELCOME************" << endl;
    cout << "\t1. Input Infomation" << endl;
    cout << "\t2. Inquiry Infomation" << endl;
    cout << "\t3. Modify Infomation" << endl;
    cout << "\t0. Exit" << endl;
    cout << "******************************" << endl;
}
void Interface_in(vector<School> &schools, vector<Game> &games) {
    int m = 0;
    while (1) {
        cout << "****************************" << endl;
        cout << "\t1.Fill Score" << endl;
        cout << "\t0.Return The Previous" << endl;
        cout << "****************************" << endl;
        int choose,modify;
        cin >> choose;
        switch (choose) {
            case 1:  for (const auto &sport : games) {
                sport.print();
            }
                     size_t dex;
                     cout << "Witch one game?" << endl;
                     cin >> dex;
                     if (games[dex - 1].getcompete() == 0) {
                         games[dex - 1].setcompete(1);
                         games[dex - 1].setscore(schools);
                         WriteData(games, schools);
                     }
                     else {
                         cout << "This game infomation has existed" << endl;
                     }
                     break;
            case 0: m = -1;
                break;
            default:cout << "Error!Input again!" << endl;;
        }
        if (m == -1)
            break;
    }
}
void Interface_out(vector<School> &schools, vector<Game> &games) {
    int m = 0;
    while (1) {
        cout << "************************************************" << endl;
        cout << "\t1.Output School Infomation" << endl;
        cout << "\t2.Output Game Infomation" << endl;
        cout << "\t3.Output School Total Rank" << endl;
        cout << "\t4.Output School Men Rank" << endl;
        cout << "\t5.Output School Women Rank" << endl;
        cout << "\t6.Output School Rank under Games" << endl;
        cout << "\t0.Return The Previous" << endl;
        cout << "************************************************" << endl;
        int choose;
        cin >> choose;
        switch (choose) {
            case 1: for (const auto &sch : schools) {
                sch.print();
            }
                    break;
            case 2: for (const auto &sport : games) {
                sport.print();
            }
                    break;
            case 3: Schoolrank(schools); break;
            case 4: Menrank(schools); break;
            case 5: Womenrank(schools); break;
            case 6: Sportrank(games); break;
            case 0: m = -1;
                break;
            default:cout << "Error!Input again!" << endl;;
        }
        if (m == -1)
            break;
    }
}
void Interface_md(vector<School> &schools, vector<Game> &games) {
    int m = 0;
    int choose;
    int add;
    int flag = 0;
    while (1) {
        cout << "***********************************************" << endl;
        cout << "\t1.Insert School" << endl;
        cout << "\t2.Insert Game" << endl;
        cout << "\t3.Delete School" << endl;
        cout << "\t4.Delete Game" << endl;
        cout << "\t5.Modify Score" << endl;
        cout << "\t0.Return The Previous" << endl;
        cout << "***********************************************" << endl;
        cin >> choose;
        switch (choose) {
            case 1:cout << "How many schools do you want to insert?" << endl;
                cin >> add;
                schools.resize(School::no + add - 1);
                WriteData(games, schools);
                break;
            case 2:cout << "How many games do you want to insert?" << endl;
                cin >> add;
                games.resize(Game::no + add - 1);
                WriteData(games, schools);
                break;
            case 3:cout << "Which one school do you want to delete?" << endl;
                cin >> add;
                for (auto s_it = schools.begin(); s_it != schools.end(); ++s_it) {
                    if (s_it->getID() == add)
                        flag = 1;
                }
                if (flag == 0) {
                    cout << "Wrong ID" << endl;
                    break;
                }
                flag = 0;
                --School::no;
                schools.erase(schools.begin() + add - 1);
                ResetID(schools);
                WriteData(games, schools);
                break;
            case 4:cout << "Which one game do you want to delete?" << endl;
                cin >> add;
                for (auto g_it = games.begin(); g_it != games.end(); ++g_it) {
                    if (g_it->getID() == add)
                        flag = 1;
                }
                if (flag == 0) {
                    cout << "Wrong ID" << endl;
                    break;
                }
                flag = 0;
                --Game::no;
                games.erase(games.begin() + add - 1);
                ResetID(games);
                WriteData(games, schools);
                break;
            case 5:for (const auto &sport : games) {
                sport.print();
            }
                   size_t dex;
                   cout << "Witch one game?" << endl;
                   cin >> dex;
                   games[dex - 1].setscore(schools);
                   WriteData(games, schools);
                   break;
            case 0:m = -1;
                break;
            default:cout << "Error!Input again!" << endl;
        }
        if (m == -1)
            break;
    }
}
void Schoolrank(vector<School> &schools) {
    vector<School> s;
    s.assign(schools.begin(), schools.end());
    stable_sort(s.begin(), s.end(),
                [](const School &a, const School &b)
    {return a.getscore() > b.getscore(); });
    cout << "*******RANK*******" << endl;
    for (const auto o : s)
        o.print();
    cout << endl << endl;
}

void Sportrank(vector<Game> &games) {
    size_t i;
    int flag = 0;
    cout << "*******RANK*******" << endl;
    for (const auto &s : games) {
        s.print();
    }
    cout << "witch one ?" << endl;
    cin >> i;
    for (auto g_it = games.begin(); g_it != games.end(); ++g_it) {
        if (g_it->getID() == i)
            flag = 1;
    }
    if (flag == 0) {
        cout << "Wrong ID" << endl;
    } else if (games[i - 1].getcompete() == 1) {
        games[i - 1].printrank();
        cout << endl << endl;
    } else {
        cout << "This game hasn't competed!" << endl;
    }
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



void ReadGameData(ifstream &infile, vector<Game> &games) {
    string s;
    getline(infile, s);
    if (s.find("No") != string::npos) {
        auto pos = s.find(":") + 1;
        Game::no = stoi(s.substr(pos));
    }
    Game temp(0);
    int flag = 1;
    while (getline(infile, s)) {
        auto pos = s.find(":") + 1;
        if (pos == s.size()) {
            if (flag < 5) {
                ++flag;
            } else {
                games.push_back(temp);
                temp.clean_rank();
                flag = 1;
            }
            continue;
        }
        if (s.find("ID") != string::npos) {
            temp.setID(stoi(s.substr(pos)));
        } else if (s.find("Name") != string::npos) {
            temp.setName(s.substr(pos));
        } else if (s.find("Sex") != string::npos) {
            temp.setsex(stoi(s.substr(pos)));
        } else  if (s.find("Compete") != string::npos) {
            temp.setcompete(stoi(s.substr(pos)));
        } else if (s.find("Winners") != string::npos) {
            temp.setwinners(stoi(s.substr(pos)));
        } else if (s.find("Rank") != string::npos) {
            auto pos = s.find(":") + 1;
            auto space_next = s.find(" ") + 1;
            while (1) {
                temp.rankpushback(stoi(s.substr(pos, space_next - pos)));
                s = s.substr(space_next);
                pos = 0;
                if (s.find(" ") == string::npos)
                    break;
                else
                    space_next = s.find(" ") + 1;
            }
        }
        if (flag != 5)
            ++flag;
        else {
            flag = 1;
            games.push_back(temp);
            temp.clean_rank();
        }
    }
}
void ReadSchoolData(ifstream &infile, vector<School> &schools) {
    string s;
    getline(infile, s);
    if (s.find("No") != string::npos) {
        auto pos = s.find(":") + 1;
        School::no = stoi(s.substr(pos));
    }
    School temp(0);
    int flag = 1;
    while (getline(infile, s)) {
        auto pos = s.find(":") + 1;
        if (pos == s.size()) {
            if (flag < 4) {
                ++flag;
            } else {
                schools.push_back(temp);
                flag = 1;
            }
            continue;
        }
        if (s.find("ID") != string::npos) {
            temp.setID(stoi(s.substr(pos)));
        } else if (s.find("Mscore") != string::npos) {
            temp.setmscore(stoi(s.substr(pos)));
        } else if (s.find("Wscore") != string::npos) {
            temp.setwscore(stoi(s.substr(pos)));
        } else if (s.find("Name") != string::npos) {
            temp.setName(s.substr(pos));
        }
        if (flag != 4)
            ++flag;
        else {
            flag = 1;
            schools.push_back(temp);
        }
    }
}
void ResetID(vector<School> &schools) {
    int i = 1;
    for (auto &sch : schools) {
        sch.setID(i);
        ++i;
    }
}
void ResetID(vector<Game> &games) {
    int i = 1;
    for (auto &g : games) {
        g.setID(i);
        ++i;
    }
}
void Menrank(vector<School> &schools) {
    vector<School> s;
    s.assign(schools.begin(), schools.end());
    stable_sort(s.begin(), s.end(),
                [](const School &a, const School &b)
    {return a.getmscore() > b.getmscore(); });
    cout << "*******MEN RANK*******" << endl;
    for (const auto &o : s)
        o.print();
    cout << endl << endl;
}
void Womenrank(vector<School> &schools) {
    vector<School> s;
    s.assign(schools.begin(), schools.end());
    stable_sort(s.begin(), s.end(),
                [](const School &a, const School &b)
    {return a.getwscore() > b.getwscore(); });
    cout << "*******WOMEN RANK*******" << endl;
    for (const auto &o : s)
        o.print();
    cout << endl << endl;
}