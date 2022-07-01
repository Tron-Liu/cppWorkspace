#include <iostream>
#include <string>
#include "Person.h"
#include "Utils.h"

// 键索引计数法

int main() {
  int R = 4;
  int numPerson = 20;
  std::string fileName = "data/key.txt";
  Person* person = new Person[numPerson];

  Utils util;
  util.loadData(person, numPerson, fileName);

  // 频率统计
  int count[R + 1] = {0};
  int key = 0;
  for (int i = 0; i < numPerson; i++) {
    key = person[i].get_key();
    count[key + 1]++;
  }
  // 将频率转换为索引
  for (int r = 0; r < R; r++) {
    count[r + 1] += count[r];
  }
  // aux : 辅助数组
  Person* aux = new Person[numPerson];
  // 遍历待排序数组
  int pos = 0;
  for (int i = 0; i < numPerson; i++) {
    key = person[i].get_key();
    pos = count[key];
    aux[pos] = person[i];
    count[key]++;
  }
  for (int i = 0; i < numPerson; i++) {
    std::cout << aux[i] << std::endl;
  }

  delete[] person;
  delete[] aux;
  return 0;
}
