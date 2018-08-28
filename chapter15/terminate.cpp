
#include <iostream>
#include <exception>
using namespace std;

int set_terminate()
{
    return 1;
}

void myQuit()
{
    cout << 111 << endl;
}

set_terminate(myQuit);

int main()
{
    throw 1;
    return 1;
}
