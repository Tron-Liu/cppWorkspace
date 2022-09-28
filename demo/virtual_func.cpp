// https://www.cnblogs.com/crbhf/p/14924629.html
/**
 * C++ 的多态性，总结下来就是：在基类的函数前加上 virtual 关键字，在派生类中重写该函数
 * 运行时将会根据所指对象的实际类型来调用相应的函数，如果对象类型是派生类，就调用派生类的函数
 * 如果对象类型是基类，就调用基类的函数
 */
#include <iostream>

class Base {
 public:
  virtual void func() { std::cout << "Base::func()" << std::endl; }
};

class Son1 : public Base {
  virtual void func() override { std::cout << "Son1::func()" << std::endl; }
};

class Son2 : public Base {};

int main() {
  Base* base = new Son1;
  base->func();
  base = new Son2;
  base->func();
  delete base;
  base = NULL;

  return 0;
}