
#include <iostream>
using namespace std;

class Test1
{
    public:
        void func(){}
};

class Test2 : public Test1
{
    private:
        void func(){}
};

class Test3 : public Test2
{

};

int main()
{
    Test3 tmp;
    tmp.func();
    return 1;
}
