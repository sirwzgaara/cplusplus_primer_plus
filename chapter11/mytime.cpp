
#include <iostream>
#include "mytime.h"
using namespace std;

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

Time::~Time()
{
}

Time Time::operator+(const Time &t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time &t) const
{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = minutes + 60 * hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot2) / 60;

    return diff;
}

Time Time::operator*(double n) const
{
    Time result;
    long totalminutes = hours * n * 60 + minutes;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

void Time::show() const
{
    cout << "hours is " << hours << ", minutes is " << minutes 
        << endl;
}

Time operator*(double m, const Time &t)
{
    Time result;
    long totalminutes = t.hours * m * 60 + t.minutes * m;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;

    return result;
}

ostream & operator<<(ostream & os, const Time & t)
{
    cout << "hours is " << t.hours << endl;
    cout << "minutes is " << t.minutes << endl;
    return os;
}
