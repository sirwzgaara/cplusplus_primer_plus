
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <math.h>
using namespace std;

void show(double v)
{
    cout << v << " ";
}

void func1()
{
    double arr[5] = {1, 4, 9, 16, 25};
    vector<double>tmp(arr, arr + 5);

    /* 预定义运算符transform，将一个迭代器区间的内容复制到另一个位置，并对每个内容应用sqrt函数 */
    transform(tmp.begin(), tmp.end(), ostream_iterator<double, char>(cout, " "), sqrt);
    cout << endl;

    /* 预定义类函数对象plus */
    plus<double> add;
    double t = add(1, 2.1);
    cout << t << endl;
}

void func2()
{
    double arr1[] = {28, 29, 30, 35, 38, 59};
    double arr2[] = {63, 65, 69, 75, 80, 99};
    vector<double>gr8(arr1, arr1 + 6);
    vector<double>m8(arr2, arr2 + 6);

    /* 5个参数的transform，使用二元函数 */
    vector<double>sum(6);
    transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), plus<double>());
    for_each(sum.begin(), sum.end(), show);
    cout << endl;

    /* 使用bind1st提供适配器，将二元函数转换为一元函数 */
    vector<double>prod(6);
    transform(gr8.begin(), gr8.end(), prod.begin(), bind1st(multiplies<double>(), 2.5));
    for_each(prod.begin(), prod.end(), show);
    cout << endl;
}

int main()
{
    func2();
    return 1;
}
