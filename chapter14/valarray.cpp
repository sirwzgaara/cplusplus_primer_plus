
#include <iostream>
#include <valarray>
using namespace std;



int main()
{
    double gpa[5] = {1.1, 1.2, 1.3, 1.4, 1.5};
    valarray<double> v(gpa, 4);
    cout << v[3] << endl;
    return 1;
}
