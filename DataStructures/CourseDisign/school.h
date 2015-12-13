#ifndef SCHOOL_H
#define SCHOOL_H
#include <string>
class School {
public:
    School() {
    	id = 1;
    }
    ~School() = default;
//protected:
    unsigned id;
    std::string name;
};

#endif //SCHOOL_H