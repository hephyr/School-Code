#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "school.h"

class Game {
public:
    Game();
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
    void setName(std::string n) {
        name = n;
    }
    void setscore(std::vector<School> &S);
    void printrank();
    void writefile(std::ofstream &outfile) const;
    static int no;
private:
    std::string name;
    int id;
    int winners;
    int score5[5] = {7, 5, 3, 2, 1};
    int score3[3] = {5, 3, 2};
    std::vector<School> rank;
};
#endif //GAME_H