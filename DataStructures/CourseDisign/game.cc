#include "game.h"

Game::Game() {
    id = no++;
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
void Game::setscore(std::vector<School> &S) {
    size_t s;
    for (int i = 0; i != winners; ++i) {
        std::size_t j = 0;
        for (const auto &school : S) {
            std::cout << school.getID() << std::endl;
        }
        std::cout << "Input the No." << i << " school id." << std::endl;
        std::cin >> s;
        rank.push_back(S[s-1]);
        if (winners == 3)
            S[s-1].score += score3[s-1];
        else
            S[s-1].score += score5[s-1];

    }
}