#ifndef SCHOOL_H
#define SCHOOL_H
#include <iostream>
#include <string>
class School {
public:
    School() {
        schid = no++;
    }
    ~School() = default;
    int getID() {
        return schid;
    }
private:
    static int no;
    int schid;
    std::string name;
};
#endif //SCHOOL_H