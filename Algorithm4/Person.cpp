#include "Person.h"

Person::Person()
{
    this->name = "";
    this->key = 0;
}
Person::Person(std::string name, int key)
{
    this->name = name;
    this->key = key;
}
Person::~Person()
{
}

void Person::set_name(std::string name)
{
    this->name = name;
}

void Person::set_key(int key)
{
    this->key = key;
}

std::string Person::get_name()
{
    return this->name;
}

int Person::get_key()
{
    return this->key;
}

std::ostream &operator<<(std::ostream &os, const Person &person)
{
    os << "name: " << person.name << " key: " << person.key << std::endl;
    return os;
}