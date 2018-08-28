
#include <iostream>
using namespace std;

class Test1
{
protected:
    int i;
};

class Test2 : public Test1
{
public:
    void lala(){cout << i << endl;}
};

int main()
{
    Test2 tmp;
    return 1;
}
