#ifndef UTILS_H_
#define UTILS_H_

#include "Person.h"

class Utils
{
private:
    
public:
    Utils();
    ~Utils();

    void loadData(Person *person, int numPerson, std::string fileName);
};

#endif
