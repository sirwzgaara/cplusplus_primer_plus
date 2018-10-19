
#include <iostream>
using namespace std;

class A
{
private:
    int i;
public:
    A(int _i = 0) : i(_i){}
    A operator+(A & a);
    operator double() const;
};

A A::operator+(A & a)
{
    cout << i << endl;
    A tmp;
    tmp.i = i + a.i;
    return tmp;
}

A::operator double() const
{
    return 10.1;
}

void func()
{
    A a(10);
    double g = a;
    cout << g << endl;
    cout << a << endl;
}

int main()
{
    func();
    return 1;
}
