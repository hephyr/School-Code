#ifndef SCHOOL_H
#define SCHOOL_H
#include <iostream>
#include <string>

class School {
   friend class Game;
public:
    School() {
        id = no++;
        score = 0;
    }
    ~School() = default;
    int getID() {
        return id;
    }
    void print() {
        std::cout << "ID." << id << "  score:" << score << std::endl;
    }

    static int no;
private:
    int id;
    int score;
    std::string name;
};
#endif //SCHOOL_H