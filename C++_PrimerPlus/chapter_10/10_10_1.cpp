#include <iostream>
#include "10_10_1.h"

int main()
{
    Account a;
    Account b("Tom", "123456", 100);
    a.show();
    std::cout << std::endl;
    
    b.take(120);
    b.show();
    std::cout << std::endl;

    b.save(100);
    b.show();
    std::cout << std::endl;

    b.take(20);
    b.show();
    std::cout << std::endl;

    return 0;
}