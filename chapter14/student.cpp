
#include <iostream>
#include <valarray>
using namespace std;

/* 通过包含实现has-a关系 */
class Student1
{
private:
    typedef valarray<double> ArrayDb;
    string name;
    ArrayDb scores;
public:
    double Average() const;
};

/* 通过对象名调用包含对象方法 */
double Student1::Average() const
{
    if (scores.size() > 0)
        return scores.sum() / scores.size();
    return 0;
}

/* 通过私有继承实现has-a关系 */
class Student2 : private string, private valarray<double>
{
public:
    /* 使用using声明使私有继承的基类方法变成公有的 */
    using valarray<double>::min;
    double Average() const;
};

/* 通过基类名和域解析运算符或者强制类型转换调用基类方法 */
double Student2::Average() const
{
    if (valarray<double>::size() > 0)
        return valarray<double>::sum() / ((valarray<double>&)*this).size();
    return 0;
}

int main()
{
    Student2 s;
    s.min();
    return 1;
}
