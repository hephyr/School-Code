#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "school.h"

class Game {
public:
    Game();
    ~Game() = default;
    void printgamename();
    void setscore(std::vector<School> &S);

    static int no;
private:
    std::string name;
    int id;
    int winners;
    unsigned score5[5] = {7, 5, 3, 2, 1};
    unsigned score3[3] = {5, 3, 2};
    std::vector<School> rank;
};
#endif //GAME_H