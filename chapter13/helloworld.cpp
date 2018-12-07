
#include <iostream>
#include <cstring>
using namespace std;

class Brass
{
protected:
    int i;
};

class BrassPlus : public Brass
{
public:
    void test(){i = 1;}
};

void func()
{
    BrassPlus a;
    a.test();
}

int main()
{
    func();
    return 1;
}
