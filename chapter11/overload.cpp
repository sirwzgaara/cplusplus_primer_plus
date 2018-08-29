
#include <iostream>
using namespace std;


class Test
{
private:
    int i;
public:
    Test(int _i = 0) : i(_i) {}
    ~Test(){}
    Test operator+(const Test & t) const;
    Test operator-(const Test & t) const;
    Test operator*(double n) const;
friend Test operator*(double n, const Test & t);
friend ostream & operator<<(ostream & os, const Test & t);
};

Test Test::operator+(const Test & t) const
{
    Test tmp;
    tmp.i = i + t.i;
    return tmp;
}

Test Test::operator-(const Test & t) const
{
    Test tmp;
    tmp.i = i - t.i;
    return tmp;
}

Test Test::operator*(double n) const
{
    Test tmp;
    tmp.i = i * n;
    return tmp;
}

Test operator*(double n, const Test & t)
{
    return t * n;
}

ostream & operator<<(ostream & os, const Test & t)
{
    os << t.i;
    return os;
}

int main()
{
    return 1;
}
