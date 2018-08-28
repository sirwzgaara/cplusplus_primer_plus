
#include <iostream>
using namespace std;

class Test1
{
private:
    int i;
public:
    Test1(int ii = 2){i = ii;}
friend void func1(const Test1 & t1){cout << t1.i << endl;}
};

class Test2 : public Test1
{
private:
    int j;
public:
    Test2(){}
friend void func2(const Test2 & t2){func1(t2);cout << "hhhh" << endl;}
};


int main()
{
    Test1 t1(10);
    Test2 t2;
    func2(t2);
    return 1;
}
