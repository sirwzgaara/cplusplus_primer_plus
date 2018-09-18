
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

void outint(const int x)
{
    cout << x << endl;
}

int main()
{
    list<int> tmp1;
    int a[] = {1, 2};
    tmp1.insert(tmp1.begin(), a, a + 2);
    for_each(tmp1.begin(), tmp1.end(), outint);

    list<int> tmp2;
    tmp2.splice(tmp2.begin(), tmp1);

    copy(tmp1.begin(), tmp1.end(), ostream_iterator<int, char>(cout, " " ));
    cout << endl;

    return 1;
}
