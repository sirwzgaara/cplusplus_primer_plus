
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

/* 此函数用作for_each的第三个函数符参数 */
void outint(const int x)
{
    cout << x << endl;
}

/* 此函数用于remove_if传入的一元谓词 */
bool toobig(int n)
{
    if (n > 2)
        return true;
    return false;
}

template <typename T>
class TooBig
{
private:
    T cutoff;
public:
    TooBig(const T & t) : cutoff(t){}
    bool operator()(const T & t){return t > cutoff;}
};

int main()
{
    list<int> tmp1;
    int a[] = {1, 2};

    /* 插入一个区间 */
    tmp1.insert(tmp1.begin(), a, a + 2);
    for_each(tmp1.begin(), tmp1.end(), outint);

    list<int> tmp2;
    /* splice移动原始空间，原始空间不能再用了 */
    tmp2.splice(tmp2.begin(), tmp1);

    copy(tmp1.begin(), tmp1.end(), ostream_iterator<int, char>(cout, " " ));

    /* 对remove_if传入一个一元谓词 */
    tmp2.remove_if(toobig);

    /* 对remove_if传入一个重载了()的类对象 */
    TooBig<int>f1(100);
    /* 两种方式，显式对象和匿名对象 */
    tmp2.remove_if(f1);
    tmp2.remove_if(TooBig<int>(1));
    cout << tmp2.size() << endl;
    return 1;
}
