#ifndef TEN_TEN_ONE_H
#define TEN_TEN_ONE_H

#include <string>

class Account
{
private:
    std::string name;
    std::string ID;
    double money;
public:
    Account();
    Account(const std::string name, const std::string ID, const double money);
    ~Account();
    void save(double money);
    void take(double money);
    void show();
};

#endif