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
void Game::print() {
    std::cout << "ID." << id << " " << name << std::endl;
}
void Game::setscore(std::vector<School> &S) {
    size_t s;
    for (int i = 0; i != winners; ++i) {
        std::size_t j = 0;
        std::cout << "Schools:" << std::endl;
        for (auto &school : S) {
            std::cout << "ID."<< school.getID() << std::endl;
        }
        std::cout << "Input the No." << i+1 << " school id." << std::endl;
        std::cin >> id;
        if (winners == 3) {
            S[id-1].addscore(score3[i]);
            rank[S[id-1].getID()] = score3[i];
        } else {
            S[id-1].addscore(score5[i]);
            rank[S[id-1].getID()] = score5[i];
        }
    }
}
void Game::printrank() {
    size_t i = 0;
    for (const auto &sch : rank) {
        std::cout << "ID." << sch.first << " Score:" << sch.second << std::endl;
    }
}