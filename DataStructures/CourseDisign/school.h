#ifndef SCHOOL_H
#define SCHOOL_H
#include <iostream>
#include <string>
#include <fstream>

class School {
   friend class Game;
public:
    School() {
        id = no++;
        score = 0;
    }
    ~School() = default;
    int getID() const {
        return id;
    }
    void setID(int i) {
        id = i;
    }
    void print() const {
        std::cout << "ID." << id << "  score:" << score << std::endl;
    }
    int getscore() const {
        return score;
    }
    void setscore(int s) {
        score = s;
    }
    void addscore(int s) {
        score += s;
    }
    void writefile(std::ofstream &outfile) const {
        outfile << "ID:"<< id << std::endl;
        outfile << "Score:" << score << std::endl;
        outfile << "SchoolName:" << name << std::endl;
    }
    void setName(std::string n) {
        name = n;
    }
    static int no;
private:
    int id;
    int score;
    std::string name;
};
#endif //SCHOOL_H