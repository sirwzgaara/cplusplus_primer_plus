
#include <iostream>
using namespace std;

template <typename T1, typename T2 = int>
class Test
{
};

template<>
class Test<double>
{};

int main()
{
    Test<int> tmp;
    return 1;
}
