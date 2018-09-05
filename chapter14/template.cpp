
#include <iostream>
using namespace std;

/* 使用非泛型参数，这里是int n */
template <typename T, int n>
class Test
{
private:
    T a[n];
};

/* 显式实例化，生成类定义 */
template class Test<int, 100>;

/* 显式具体化，为特定参数类型产生类声明 */
template <> 
class Test<const char *, 100>
{
private:
    int j;
};

/* 使用多个类型参数 */
template <typename T1, typename T2 = int>
class Pair
{
private:
    T1 a;
    T2 b;
public:
    T1 & first();
    T2 & second();
    T1 first() const{return a;}
    T2 second() const{return b;}
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval){}
    Pair(){}
};

template <typename T1, typename T2>
T1 & Pair<T1, T2>::first()
{
    return a;
}

template <typename T1, typename T2>
T2 & Pair<T1, T2>::second()
{
    return b;
}

/* 部分具体化，使用多个泛型参数时可用 */
template <typename T1>
class Pair<T1, int>
{
    
};

/* 部分具体化对模板进行限制的一个有意思的方式 */
template <typename T1, typename T2, typename T3>
class Feeb
{};

template <typename T1>
class Feeb<T1, T1*, T1*>
{};

void func()
{
    Pair<double> tmp;
}

int main()
{
    func();
    Test<int, 100> tmp;         //隐式实例化
    return 1;
}
