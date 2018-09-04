
#include <iostream>
using namespace std;

class Test
{
public:
    virtual void lala()=0;
} ;

class Child : public Test
{
public:
    virtual void lala(){}
};

int main()
{
    Child tmp;
    return 1;
}
