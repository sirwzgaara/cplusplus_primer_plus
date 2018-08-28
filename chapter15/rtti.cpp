
#include <iostream>
#include <typeinfo>
using namespace std;

class Grand
{
public:
    virtual ~Grand(){}
};

class Superb : public Grand
{

};

class Magnificent : public Superb
{

};

int main()
{
    Grand * pg = new Grand;
    Grand * ps = new Superb;
    Grand * pm = new Magnificent;

    Magnificent * p1 = (Magnificent *)pm;
    Magnificent * p2 = (Magnificent *)pg;
    Superb * p3 = (Magnificent *)pm;

    Superb * p4 = dynamic_cast<Superb *>(pg);
    if (!p4)
        cout << 1 << endl;
    if (typeid(Magnificent) == typeid(*pm))
        cout << 2 << endl;

    double *pint;
    cout << typeid(*pint).name() << endl;

    return 1;
}
