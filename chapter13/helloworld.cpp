
#include <iostream>
#include <cstring>
using namespace std;

class Test
{
private:
    char * str;
public:
    Test(){str = NULL;}
    Test(const char *);
    Test(const Test &);
    Test & operator=(const Test &);
    ~Test();
};

Test::Test(const char * s)
{
    str = new char [strlen(s)];
    strcpy(str, s);
}

Test::Test(const Test & t)
{
    str = new char[strlen(t.str)];
    strcpy(str, t.str);
}

Test & Test::operator=(const Test &t)
{
    if (this != &t)
    {
        Test local(t);
        char * tmp = str;
        str = local.str;
        local.str = tmp;
    }
    return *this;
}

Test::~Test()
{
    delete [] str;
}

int main()
{
    return 1;
}
