
#include <iostream>
using namespace std;


template <typename T>
class Stack
{

};

/* 将模板用作其他模板的参数 */
template <template <typename T> class Thing, typename U, typename V>
class Crab
{
private:
    Thing<U> a;
    Thing<V> b;
};

int main()
{
    Crab<Stack, int, double> tmp;
    return 1;
}
