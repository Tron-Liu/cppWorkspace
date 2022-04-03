#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

class Person
{
  private:
    std::string name;
    int key;

  public:
    Person();
    Person(std::string name, int key);
    ~Person();

    void set_name(std::string);
    void set_key(int key);
    std::string get_name();
    int get_key();
    friend std::ostream &operator<<(std::ostream &os, const Person &person);
};

#endif