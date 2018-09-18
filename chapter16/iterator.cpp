
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void output(const int & x)
{
    cout << x << " ";
}

void func1()
{
    int casts[10] = {6, 7, 2, 9, 4, 11, 8, 7, 10, 5};
    vector<int> dice(10);

    /* 对数组应用迭代器算法 */
    copy(casts, casts + 10, dice.begin());

    /* 按照正序和逆序输出vector */
    copy(dice.begin(), dice.end(), ostream_iterator<int, char>(cout, " "));
    cout << endl;
    copy(dice.rbegin(), dice.rend(), ostream_iterator<int, char>(cout, " "));
    cout << endl;

    /* 使用for_each函数遍历，对每个对象调用output函数 */
    for_each(dice.begin(), dice.end(), output);
    cout << endl;
}

int main()
{
    func1();
    return 1;
}
