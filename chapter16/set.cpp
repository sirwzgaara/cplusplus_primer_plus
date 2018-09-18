
#include <iostream>
#include <iterator>
#include <set>
#include <algorithm>
using namespace std;

void func()
{
    const int N = 6;
    string s1[N] = {"ab", "ab", "dc", "cc", "ee", "ff"};

    /* 从字符数组中构造一个set */
    set<string>tmp1(s1, s1 + N);
    copy(tmp1.begin(), tmp1.end(), ostream_iterator<string, char>(cout, " "));
    cout << endl;

    /* set_union, set_intersection, set_difference */
    set<string>tmp2(s1 + 2, s1 + 3);
    set<string>tmp3;

    /* 最后一个参数需要插入迭代器 */
    set_intersection(tmp1.begin(), tmp1.end(), tmp2.begin(), tmp2.end(),
            insert_iterator<set<string> >(tmp3, tmp3.begin()));

    copy(tmp3.begin(), tmp3.end(), ostream_iterator<string, char>(cout, " "));
    cout << endl;
}

int main()
{
    func();
    return 1;
}
