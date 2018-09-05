
#include <iostream>
using namespace std;

class A
{
private:
    int i;
public:
    A(int ii = 0){i = ii;}
    A(const A & a){i = a.i;}
    void show() const {cout << "a" << endl;}
};

class B : virtual public A
{
private:
    int j;
public:
    B(){}
    B(const A & a, int jj) : A(a), j(jj){}
    void show() const{cout << "b" << endl;}
};

class C : virtual public A
{
private:
    int k;
public:
    C(){}
    C(const A & a, int kk) : A(a), k(kk){}
    void show() const{cout << "c" << endl;}
};

class D : public B, public C
{
public:
    D(){}
    D(const A & a, int jj, int kk) : A(a), B(a, jj), C(a, kk){}
};

int main()
{
    A a(1);
    D d(a, 2, 3);
    d.B::show();
    return 1;
}
