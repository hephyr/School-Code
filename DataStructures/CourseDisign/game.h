#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include "school.h"

class Game : public School{
public:
    Game();
    ~Game() = default;
    void printgamename();
    void getscore(const std::list<School> &S) {
        for (int i = 0; i != winners; ++i) {
            std::list<School>::size_type j = 0;
            for ( )
            // std::cout << "Please input the No." << i << " score :";
            // std::cin >> 
        }
    }
private:
    std::tring name;
    unsigned winners;
    unsigned score5[5] = {7, 5, 3, 2, 1};
    unsigned score3[3] = {5, 3, 2};
    list<
};
#endif //GAME_H