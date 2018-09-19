
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

void func()
{
    int i = 0;
    while (i--)
    {
        break;
    }
    cout << i << endl;
}

int main()
{
    func();
    return 1;
}
