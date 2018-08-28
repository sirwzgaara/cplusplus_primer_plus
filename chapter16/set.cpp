
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

void func()
{
    const int N = 6;
    string s1[N] = {"ab", "ab", "dc", "cc", "ee", "ff"};
    set<string> A(s1, s1 + N);
    ostream_iterator<string, char>out(cout, " ");
    copy(A.begin(), A.end(), out);
}

int main()
{
    func();
    return 1;
}
