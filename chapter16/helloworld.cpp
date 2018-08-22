
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class empty
{

};

int main()
{
    double prices[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    for (double x : prices)
        cout << x << endl;
    return 1;
}
