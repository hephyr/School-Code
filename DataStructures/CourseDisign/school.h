#ifndef SCHOOL_H
#define SCHOOL_H
#include <string>
class School {
public:
    School();
    ~School() = default;
protected:
    unsigned id;
    std::string name;
};

#endif //SCHOOL_H