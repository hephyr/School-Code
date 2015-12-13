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
    int getID() const {
        return schid;
    }
    static int num = 1;
private:
    int schid;
    std::string name;
};
// int School::num = 1;
#endif //SCHOOL_H