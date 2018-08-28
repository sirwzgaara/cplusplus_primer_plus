
#ifndef _MYTIME_H
#define _MYTIME_H
#endif

#include <iostream>
using namespace std;

class Time
{
friend Time operator*(double m, const Time & t);
friend ostream & operator<<(ostream & os, const Time & t);
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    ~Time();
    Time operator+(const Time &t) const;
    Time operator-(const Time &t) const;
    Time operator*(double n) const;
    void show() const;
};
