#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "school.h"

class Game {
public:
    Game();
    Game(int i);
    ~Game() = default;
    int getID() const {
        return id;
    }
    void print() const;             //输出项目编号，名称，男团，女团
    void setID(int i) {
        id = i;
    }
    void setwinners(int w) {
        winners = w;
    }
    void setsex(int s) {
        sex = s;
    }
    void setName(std::string n) {
        name = n;
    }
    void setcompete(int c) {
        compete = c;
    }
    int getcompete() {
        return compete ;
    }
    void rankpushback(int i) {
        rank_id.push_back(i);
    }
    void clean_rank() {
        rank_id.clear();
    }
    void setscore(std::vector<School> &S);          //对成绩赋值
    void printrank();                               //输出项目排名
    void writefile(std::ofstream &outfile) const;   //写入文件
    static int no;
private:
    std::string name;
    int id;
    int sex;
    int winners;
    int compete=0;
    int score5[5] = {7, 5, 3, 2, 1};
    int score3[3] = {5, 3, 2};
    std::vector<int> rank_id;                       //存储成绩排名
};
#endif //GAME_H