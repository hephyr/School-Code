#include "game.h"

Game::Game() {
    std::cout << "Please input the game name :";
    std::cin >> name;
    while (1) {
	    std::cout << "5 winners or 3 winners ? :";
	    std::cin >> winners;
	    if (winners == 3 || winners == 5) {
	    	break;
	    } else {
	    	std::cout << "wrong numbers. Input again." << std::endl;
	    }
	}
}
void Game::printgamename() {
    std::cout << name << std::endl;
}
void Game::getscore(std::list<School> &S) {
    for (int i = 0; i != winners; ++i) {
        std::size_t j = 0;
        for (const auto &school : S) {
        	// std::cout << "ID: " << std::endl;
        }
        // std::cout << "Please input the No." << i << " score :";
        // std::cin >> 
    }
}