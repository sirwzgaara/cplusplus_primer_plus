
#include <iostream>
using namespace std;


int main()
{
    int *p;
    const char *a;
    a = reinterpret_cast<char *>(p);
    return 1;
}
