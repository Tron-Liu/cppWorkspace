#include "Utils.h"
#include <fstream>
#include <string.h>
#include <string>

Utils::Utils()
{
}

Utils::~Utils()
{
}

void Utils::loadData(Person *person, int numPerson, std::string fileName)
{
    std::ifstream infile;
    infile.open(fileName, std::ios::in);
    if (!infile.is_open())
    {
        std::cerr << "Failed to open file " << fileName << std::endl;
    }

    char buffer[1024] = {0};
    std::string name = "";
    int key = 0;
    int lengthOfLine = 0;
    int i = 0;
    for (int i = 0; i < numPerson; i++)
    {
        infile.getline(buffer, sizeof(buffer));
        lengthOfLine = strlen(buffer);
        name = std::string(buffer, 0, lengthOfLine - 2);
        key = atoi(buffer + lengthOfLine - 1);

        person[i].set_name(name);
        person[i].set_key(key);
    }
    infile.close();
}