#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <vector>
class Array {
public:
    Array() = default;
    Array(int j, int i);
    void print() const;
    Array &Write();
    Array &Write(int j,int i,int e);
    Array &Warshall();
private:
    std::vector<std::vector<int>> v;
};

Array::Array(int j, int i) {
    for (int p = 0; p != j; ++p) {
        std::vector<int> temp(i, 0);
        v.push_back(temp);
    }
    this->Write();
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
#endif //ARRAY_H