#include <iostream>

class Student {
 public:
  Student(std::string name, int age) {
    this->name = name;
    this->age  = age;
  }
  void print() { std::cout << name << " " << age << std::endl; }

 private:
  std::string name;
  int age;

  static Student* s_instance;
};

int main() {
  Student* Tom = new Student("Tom", 20);
  Tom->print();
  delete Tom;

  return 0;
}