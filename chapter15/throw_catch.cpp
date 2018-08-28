
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class Test : public exception
{
    const char * what(){return "error";}
};

void func() throw(Test)
{
    throw 1.0;
}

int main()
{
    try {
        int i = 1;
    }
    catch (int)
    {
        cout << 1 << endl;
    }
    catch (...)
    {
        
    }
    return 1;
}
