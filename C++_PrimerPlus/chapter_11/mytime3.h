#ifndef MYTIME3_H_
#define MYTIME3_H_

#include <iostream>

class Time
{
private:  
    /* data */
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(const int h = 0, const int m = 0);
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(double mult) const;

    friend Time operator*(double m, const Time & t);

    friend std::ostream & operator<<(std::ostream & os, const Time & t);

    ~Time();
};

#endif