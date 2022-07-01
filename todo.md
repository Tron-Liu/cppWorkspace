# todo

```cpp
class Test {
 public:
  Test() {}
  Test(int _m) : _cm(_m) {}  // TODO: 了解这一种成员变量初始化的意义
  int get_cm() const         // TODO: 了解将限定词放在函数的意义
  {
    return _cm;
  }

 private:
  int _cm;
};
```
