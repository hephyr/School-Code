#include <iostream>
#include <vector>
#include <fstream>
#include "Array.h"
Array::Array(int j, int i) {
    for (int p = 0; p != j; ++p) {
        std::vector<int> temp(i, 0);
        v.push_back(temp);
    }
    //this->Write();
}
void Array::print() const {
    for (auto &itemj : v) {
        for (auto &itemi : itemj)
            std::cout << itemi << " ";
        std::cout << std::endl;
    }
}
Array &Array::Write() {
    int j = 1, i = 1;
    for (auto &item : v) {
        std::cout << "Input the value in " << j <<  " row" << std::endl;
        for (auto &val : item) {
            std::cout << i << " colomn ";
            std::cin >> val;
            ++i;
        }
        i = 1;
        ++j;
    }
    std::cout << std::endl;
    return *this;
}
Array &Array::Write(std::ifstream &infile) {
    for (auto &item :v)
        for (auto &val : item)
            infile >> val;
    return *this;
}
Array &Array::Warshall() {
    auto row = v.size();
    auto colomn = v[0].size();
    decltype(row) j = 0;
    decltype(colomn) i = 0;
    while (i != colomn) {
        while (j != row) {
            if (v[j][i] == 1) {
                for (decltype(row) count = 0; count != colomn; ++count) {
                    v[j][count] = v[j][count] + v[i][count];
                    if (v[j][count] > 1)
                        v[j][count] = 1;
                }
            }
            ++j;
        }
        j = 0;
        ++i;
    }
    return *this;
}

bool Array::operator!=(const Array &a) {
    auto row = v.size();
    auto colomn = v[0].size();
    decltype(row) j = 0;
    decltype(colomn) i = 0;
    while (j != row) {
        while (i != colomn) {
            if (v[j][i] != a.v[j][i]) {
                return true;
            }
            ++i;
        }
        i = 0;
        ++j;
    }
    return false;
}
int numline(char * argv) {
    std::ifstream infile(argv);
    int i = 0;
    std::string s;
    while (!infile.eof()) {
        infile >> s;
        ++i;
    }
    int j = static_cast<int>(sqrt(i));
    bool b = (j*j != static_cast<int>(i));
    if (b) {
        std::cerr << "Wrong data, check out \'infile\'" << std::endl;
        return -1;
    }
    return sqrt(i);
}