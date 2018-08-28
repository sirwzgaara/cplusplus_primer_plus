
#include <iostream>
#include <iterator>
#include <map>
using namespace std;

void func()
{
    multimap<int, string> codes;
    pair<const int, string>item(213, "Los Angeles");
    codes.insert(item);
    cout << item.first << endl;
    cout << item.second << endl;
}

int main()
{
    func();
    return 1;
}
