
#include <iostream>
using namespace std;

class Time
{
/* 友元乘法运算符 */
friend Time operator*(double m, const Time & t);
friend ostream & operator<<(ostream & os, const Time & t);
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time operator+(const Time & t) const;   //重载加法运算符
    Time operator-(const Time & t) const;   //重载减法运算符
    Time operator*(double n) const;         //重载乘法运算符
    void Show() const;
};

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time & t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours += hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time & t) const
{
    Time diff;
    int tot1, tot2;
    
    tot1 = t.minutes + t.hours * 60;
    tot2 = minutes + hours * 60;

    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;

    return diff;
}

/* 作为成员变量重载乘法运算符的一个问题是，乘数只能在后面 */
Time Time::operator*(double n) const
{
    Time result;
    long totalminutes = hours * n * 60 + minutes * n;

    result.minutes = totalminutes % 60;
    result.hours = totalminutes / 60;
}

Time operator*(double n, const Time & t)
{
    return t * n;
}

ostream & operator<<(ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minuts" << endl;
    return os;
}

int main()
{
    Time t1(0, 1);
    Time t2(0, 2);
    Time t3(0, 4);
    cout << t1 + t2;
    return 1;
}
