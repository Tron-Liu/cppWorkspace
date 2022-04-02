#include "10_10_1.h"
#include <iostream>

Account::Account()
{
    this->name = "";
    this->ID = "";
    this->money = 0;
}

Account::Account(const std::string name, const std::string ID, const double money)
{
    if(money < 0) {
        std::cout << "Please enter a correct number!";
    }
    else {
        this->money = money;
    }
    this->name = name;
    this->ID = ID;
}

Account::~Account()
{

}

void Account::save(const double money)
{
    this->money += money; 
}

void Account::take(const double money)
{
    if(this->money <= money)
        std::cout << "Sorry, your credit is running low";
    else
        this->money -= money; 
}

void Account::show()
{
    std::cout << "Name: " << name << std::endl
            << "ID: " << ID << std::endl
            << "Money: " << money;
}