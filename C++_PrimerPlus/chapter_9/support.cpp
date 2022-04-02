#include <iostream>
extern double warming;

static int hour = 5;
extern int hour;

void update(double dt);
void local();

using std::cout;
void update(double dt)
{
    extern double warming;
    warming += dt;
    cout << "Updating global warming to " << warming;
    cout << " degrees.\n";

    cout << hour << std::endl;
    cout << ::hour << std::endl;
}

void local()
{
    double warming = 0.8;

    cout << "Local warming = " << warming << " degrees.\n";
    cout << "But global warming = " << ::warming;
    cout << " degrees.\n";
}