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
        mscore = 0;
        wscore = 0;
    }
    School(int i) {
        if (i != 0)
            id = i;
    }
    ~School() = default;
    int getID() const {
        return id;
    }
    void setID(int i) {
        id = i;
    }
    void print() const {
        std::cout << "ID." << id << "  score:" << getscore()<<" mscore:"<<mscore<<" wscore:"<<wscore<< std::endl;
    }
    int getscore() const {
        return wscore+mscore;
        
    }
    void addmscore(int s) {
        mscore += s;
    }
    void addwscore(int s) {
        wscore += s;
    }
    void setmscore(int s) {
        mscore = s;
    }
    void setwscore(int s) {
        wscore = s;
    }
    int getmscore() const{
        return mscore;
    }
    int getwscore() const{
        return wscore;
    }
    void writefile(std::ofstream &outfile) const {
        outfile << "ID:" << id << std::endl;
        outfile << "Mscore:" << mscore << std::endl;
        outfile << "Wscore:" << wscore << std::endl;
        outfile << "SchoolName:" << name << std::endl;
    }
    void setName(std::string n) {
        name = n;
    }
    

    static int no;
private:
    int id;
    int mscore;
    int wscore;
    std::string name;
};
#endif //SCHOOL_H