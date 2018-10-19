
#include <iostream>
#include <cstring>
using namespace std;

class Test
{
private:
    char * s;
public:
    Test(char * _s);
    Test(const Test & t);
    ~Test();
    Test & operator=(const Test & t);
};

Test::Test(char * _s)
{
    int len = strlen(_s);
    s = new char [len + 1];
    strcpy(s, _s);
}

Test::Test(const Test & t)
{
    int len = strlen(t.s);
    s = new char [len + 1];
    strcpy(s, t.s);
}

Test & Test::operator=(const Test & t)
{
    if (this != &t)
    {
        Test local(t);
        char * tmp = local.s;
        local.s = s;
        s = tmp;
    }
    return *this;
}

Test::~Test()
{
    delete [] s;
}

int main()
{
    cout << sizeof(Test) << endl;
    return 1;
}
