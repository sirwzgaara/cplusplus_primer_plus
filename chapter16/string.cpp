
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string n1;
    n1 += "dd";
    cout << n1.size() << endl;
    cout << n1.length() << endl;

    string n2("dd");
    cout << n2.size() << endl;

    string n3 = {'q', 't'};
    cout << n3.size() << endl;
}
