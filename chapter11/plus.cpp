
#include <iostream>
using namespace std;

class Test
{
private:
    double i;
public:
    Test(){}
    Test(double);
    ~Test(){}
    Test operator+(const Test &t) const;
    //operator double() const{return i;}
};

Test::Test(double d)
{
    i = d;
}

Test Test::operator+(const Test &t) const
{
    Test tmp;
    tmp.i = i + t.i;
    return tmp;
}

int main()
{
    Test t1(19.6);
    double lala = 23.8;
    Test t2 = lala + t1;
    return 1;
}
