#include "Person.h"
#include "Utils.h"
#include <iostream>
#include <string>

// 键索引计数法

int main()
{
    int R = 5;
    int numPerson = 20;
    std::string fileName = "data.txt";
    Person *person = new Person[numPerson];

    Utils util;
    util.loadData(person, numPerson, fileName);

    // 频率统计
    int count[R + 1] = {0};
    int key = 0;
    for (int i = 0; i < numPerson; i++)
    {
        key = person[i].get_key();
        count[key + 1]++;
    }
    for (int r = 0; r < R; r++)
    {
        count[r + 1] += count[r];
    }

    // aux : 辅助数组
    Person *aux = new Person[numPerson];
    for(int i = 0; i < numPerson; i++)
    {
        key = person[i].get_key();
        aux[count[key]++] = person[i];
    }
    for (int i = 0; i < numPerson; i++)
    {
        std::cout << aux[i] << std::endl;
    }
    
    delete[] person;
    delete[] aux;
    return 0;
}
