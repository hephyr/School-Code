#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "school.h"

class Game {
public:
    Game();
    ~Game() = default;
    int getID() {
        return id;
    }
    void print();
    void setscore(std::vector<School> &S);
    void printrank();
    static int no;
private:
    std::string name;
    int id;
    int winners;
    unsigned score5[5] = {7, 5, 3, 2, 1};
    unsigned score3[3] = {5, 3, 2};
    std::map<int, int> rank;
};
#endif //GAME_H