
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void func1()
{
    int casts[10] = {6, 7, 2, 9, 4, 11, 8, 7, 10, 5};
    vector<int> dice(10);
    copy(casts, casts + 10, dice.begin());

    ostream_iterator<int, char>out_iter(cout, " ");
    copy(dice.begin(), dice.end(), out_iter);
}

int main()
{
    func1();
    return 1;
}
