
#include <iostream>
using namespace std;


template <typename T>
class Stack
{

};

/* 将模板用作其他模板的参数 */
template <template <typename T> class Thing>
class Crab
{
private:
    Thing<int> a;
    Thing<double> b;
};

int main()
{
    Crab<Stack> tmp;
    return 1;
}
