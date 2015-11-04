#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
int numline(char * argv);
class Array {
public:
    Array() = default;
    Array(int j, int i);
    void print() const;
    Array &Write();
    Array &Write(std::ifstream &infile);
    Array &Write(int j,int i,int e);
    Array &Warshall();
    bool operator!=(const Array &a);
private:
    std::vector<std::vector<int>> v;
};
#endif //ARRAY_H