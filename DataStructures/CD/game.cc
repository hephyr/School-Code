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
    while (1) {
        std::cout << "it's male sport or female sport?(1:male,2:female)" << std::endl;
        std::cin >> sex;
        if (sex==1||sex==2) {
            break;
        } else {
            std::cout << "wrong numbers. Input again." << std::endl;
        }
    }
}
Game::Game(int i) {
    if (i != 0)
        id = i;
}
void Game::print() const {
    std::cout << "ID." << id << " " << name;
        if (sex == 1)
            std::cout << "Sex:Female" << std::endl;
        else
            std::cout << "Sex:Male" << std::endl;
}
void Game::setscore(std::vector<School> &S) {
    size_t s;
    size_t j;

    for (int i = 0; i != winners; ++i) {

        std::cout << "Schools:" << std::endl;
        for (const auto &school : S) {
            std::cout << "ID." << school.getID() << std::endl;
        }
        while (1) {
            int m = 0;
            std::cout << "Input the No." << i + 1 << " school id." << std::endl;
            std::cin >> s;
            for (const auto school : S) {
                if (s == school.getID()) {
                    if (sex == 1) {
                        if (winners == 3) {
                            S[s - 1].addmscore(score3[i]);
                        } else {
                            S[s - 1].addmscore(score5[i]);
                        }
                        rank_id.push_back(S[s - 1].getID());
                    } else {
                        if (winners == 3) {
                            S[s - 1].addwscore(score3[i]);
                        } else {
                            S[s - 1].addwscore(score5[i]);
                        }
                        rank_id.push_back(S[s - 1].getID());
                    }
                    m = -1;
                } 
            }
            if (m == -1)
               break;
            else
               std::cout << "Error Number!Input Again!" << std::endl;
           
        }
    }
}
void Game::printrank() {
    size_t i = 0;
    for (const auto &sch : rank_id) {
        std::cout << "ID." << sch;
        if (winners == 3) {
            std::cout << " Score: " << score3[i] << std::endl;
            ++i;
        } else {
            std::cout << " Score: " << score5[i] << std::endl;
            ++i;
        }
    }
}
void Game::writefile(std::ofstream &outfile) const {
    outfile << "ID:" << id << std::endl;
    outfile << "Sex:" << sex << std::endl;
    outfile << "Compete:" << compete << std::endl;
    outfile << "Winners:" << winners << std::endl;
    outfile << "Rank:";
    for (const auto &i : rank_id) {
        outfile << i << " ";
    }
    outfile << std::endl;
}
