
#include <iostream>
#include "mytime.h"

using namespace std;

int main()
{
    Time t1(1, 0);
    Time t2(2, 0);
    Time t3(4, 0);
    Time t4 = t1 + t2 + t3;
    return 1;
}
