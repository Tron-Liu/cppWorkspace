// #include <semaphore>
#include <semaphore.h>
#include <thread>
#include <iostream>

void func(int num)
{
    for (int i = 0; i < num; i++)
    {
        std::cout << "hello world" << std::endl;
    }
}

int main()
{
    std::thread t(func, 10);
    std::cout << t.get_id() << std::endl;
    t.join();
    std::cout << std::this_thread::get_id() << std::endl;
    return 0;
}
