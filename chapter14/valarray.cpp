
#include <iostream>
#include <valarray>
using namespace std;


void func()
{
    double gpa[5] = {3.1, 3.5, 3.8, 2.9, 3.3};
    valarray<double> v1;
    valarray<int> v2(8);
    valarray<int> v3(10, 8);
    valarray<double> v4(gpa, 4);
    valarray<double> v5 = {1, 2};
}

int main()
{
    func();
    return 1;
}
