#ifndef SCHOOL_H
#define SCHOOL_H
#include <iostream>
#include <string>
class School {
public:
    School() {
        schid = num;
        ++num;
    }
    ~School() = default;
    int getID() {
        return schid;
    }
private:
    int schid;
    static int num;
    std::string name;
};
int School::no = 1;
#endif //SCHOOL_H