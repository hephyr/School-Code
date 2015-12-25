#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "school.h"

class Game {
public:
    Game();
    Game(int i);
    ~Game() = default;
    int getID() const {
        return id;
    }
    void print() const;
    void setID(int i) {
        id = i;
    }
    void setwinners(int w) {
        winners = w;
    }
    void setsex(int s) {
        sex = s;
    }
    void setName(std::string n) {
        name = n;
    }
    void setcompete(int c) {
        compete = c;
    }
    int getcompete() {
        return compete ;
    }
    void setscore(std::vector<School> &S);
    void printrank();
    void writefile(std::ofstream &outfile) const;
    static int no;
private:
    std::string name;
    int id;
    int sex;//1£ºmale 2:female;
    int winners;
    int compete=0;//0£»1£»
    int score5[5] = {7, 5, 3, 2, 1};
    int score3[3] = {5, 3, 2};
    std::vector<School> rank;
};
#endif //GAME_H