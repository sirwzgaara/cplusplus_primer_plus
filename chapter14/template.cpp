
#include <iostream>
using namespace std;

template <typename T, int n>
class Test
{
private:
    T a[n];
};

template class Test<int, 100>;  //显式实例化

template <> class Test<const char *, 100>
{
    private:
        int j;
};

int main()
{
    Test<int, 100> tmp;         //隐式实例化
    return 1;
}
