#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <list>
#include "school.h"

class Game : public School{
public:
    Game();
    ~Game() = default;
    void printgamename();
    void getscore(std::list<School> &S);
private:
    std::string name;
    unsigned winners;
    unsigned score5[5] = {7, 5, 3, 2, 1};
    unsigned score3[3] = {5, 3, 2};
    vector<School> rank;
};
#endif //GAME_H