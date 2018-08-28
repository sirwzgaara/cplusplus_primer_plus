
#include <iostream>
using namespace std;

class Test
{
private:
    int i;
public:
    Test(){}
    virtual void func() = 0;
    virtual ~Test() = 0;
};

Test::~Test(){}

class Test2 : public Test
{
public:
    void func(){}
};


int main()
{
    Test2 tmp;
    return 1;
}
