#include <iostream>
#include "game.h"

Game::Game() {
    std::cout << "Please input the game name :";
    std::cin >> name;
    std::cout << "How many winner(s) :";
    std::cin >> winner;
}
void Game::printgamename() {
    std::cout << name << std::endl;
}