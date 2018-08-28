
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ratings(5);
    ratings[0] = 9;
    for (int i = 0; i < 5; i++)
    {
        cout << ratings[i] << endl;
    }
    return 1;
}

