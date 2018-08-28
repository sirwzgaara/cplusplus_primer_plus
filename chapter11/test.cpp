
#include <iostream>
using namespace std;

class Test
{
private:
    double i;
public:
    Test(double, int = 0);
    Test(){}
    ~Test(){}
    operator double() const;
    operator int() const;
};

Test::Test(double d, int k)
{
    i = d;
}

Test::operator double() const
{
    return 1.2;
}

Test::operator int() const
{
    return 2;
}

int main()
{
    Test tmp;
    tmp = 19.6;
    long lala = (double)tmp;
    cout << lala << endl;
    return 1;
}
