
#include <iostream>
using namespace std;

class Test
{
private:
    int i;
public:
    Test(){}
    Test(int n){}
    Test(const Test & t){cout << 2 << endl;}
    ~Test(){cout << 1 << endl;}
    Test & operator=(const Test & t){cout << 3 << endl;}
};

int main()
{
    Test t;
    int n = 21;
    t = n;
    return 1;
}
