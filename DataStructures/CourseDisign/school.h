#ifndef SCHOOL_H
#define SCHOOL_H
#include <iostream>
#include <string>
class School {
public:
    School() {
        id = no++;
    }
    ~School() = default;
    int getID() {
        return id;
    }

    
    static int no;
private:
    int id;
    std::string name;
};
#endif //SCHOOL_H