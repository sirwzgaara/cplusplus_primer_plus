
#include <iostream>
#include <istream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


int main()
{
    multimap<int, string>tmp;

    /* 使用pair插入两个键值对 */
    pair<int, string>code(12, "lala");
    tmp.insert(code);
    tmp.insert(pair<int, string>(12, "qq"));

    /* count函数，返回一个键有多少个值 */
    cout << tmp.count(12) << endl;

    /* 遍历同一个键的若干值的方法 */
    /* 获取一个区间迭代器 */
    pair<multimap<int, string>::iterator, multimap<int, string>::iterator>range =
        tmp.equal_range(12);

    multimap<int, string>::iterator it;
    /* 遍历键为12的区间迭代器 */
    for (it = range.first; it != range.second; it++)
        cout << (*it).second << endl;

    return 1;
}
