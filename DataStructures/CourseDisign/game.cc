#include "game.h"

Game::Game() {
    id = no++;
    // std::cout << "Please input the game name :";
    // std::cin >> name;
    std::cout << "SPORT ID." << id << std::endl;
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
void Game::print() const {
    std::cout << "ID." << id << " " << name << std::endl;
}
void Game::setscore(std::vector<School> &S) {
    size_t s;
    for (int i = 0; i != winners; ++i) {
        std::size_t j = 0;
        std::cout << "Schools:" << std::endl;
        for (const auto &school : S) {
            std::cout << "ID."<< school.getID() << std::endl;
        }
        std::cout << "Input the No." << i+1 << " school id." << std::endl;
        std::cin >> s;
        if (winners == 3) {
            S[s-1].addscore(score3[i]);
        } else {
            S[s-1].addscore(score5[i]);
        }
        rank.push_back(S[s-1]);
    }
}
void Game::printrank() {
    size_t i = 0;
    for (const auto &sch : rank) {
        std::cout << "ID." << sch.getID();
        if (winners == 3) {
            std::cout << " Score: " << score3[i] << std::endl;
            ++i;
        } else {
            std::cout << " Score: " << score5[i] << std::endl;
            ++i;
        }
    }
}