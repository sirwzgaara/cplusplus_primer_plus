
#include <iostream>
#include <memory>
using namespace std;

class Report
{
private:
    string str;
public:
    Report(const string s) : str(s){cout << "created" << endl;}
    ~Report(){cout << "deleted" << endl;}
    void comment() const {cout << "str is " << str << endl;}
};

/* 一个不适合使用auto_ptr的例子 */
void func1()
{
    unique_ptr<string> p1(new string("hello, world"));
    unique_ptr<string> p2;
    //p2 = p1;
    cout << *p2 << endl;
    cout << *p1 << endl;        //core dumped
}

unique_ptr<string> func2_demo(const char *s)
{
    unique_ptr<string> tmp(new string(s));
    return tmp;
}

/* unique_ptr的关于赋值的一个特性 */
void func2()
{
    unique_ptr<string> ps;
    ps = func2_demo("hello, world");
}

void func3()
{
    unique_ptr<string> p1(new string("hello, world"));
    unique_ptr<string> p2;
    p2 = move(p1);
    cout << *p1 << endl;
}

/* unique_ptr数组变体 */
void func4()
{
    unique_ptr<double> p1(new double[4]);
    //auto_ptr<double> p2(new double[4]);
    shared_ptr<double>p3(new double[4]);
}

/* shared_ptr */
void func5()
{
    shared_ptr<string> ps = func2_demo("hello, world");
}

/* 使用指向类的auto_ptr */
void func6()
{
    auto_ptr<Report> ps(new Report("using auto_ptr"));
    ps->comment();
}

int main()
{
    auto_ptr<double> pd(new double);        //一个智能指针的使用方式

    //func1();
    //func2();
    //func3();
    //func4();
    func5();
    //func6();

    return 1;
}
