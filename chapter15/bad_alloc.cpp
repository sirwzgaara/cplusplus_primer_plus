
#include <iostream>
#include <cstdlib>
using namespace std;

struct Big
{
    double stuff[20000];
};

int main()
{
    Big * pb;
    try {
        cout << "before new" << endl;
        pb = new (newthrow) Big[100000];
        cout << "after new" << endl;
    }
    catch (bad_alloc & ba)
    {
        cout << "bad_alloc" << endl;
        cout << ba.what() << endl;
        exit(EXIT_FAILURE);
    }
    return 1;
}
