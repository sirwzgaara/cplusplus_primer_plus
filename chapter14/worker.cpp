
#include <iostream>
#include <string>
using namespace std;

/* 始祖类 */
class Worker
{
private:
    string fullname;
    long id;
public:
    Worker() : fullname("no one"), id(0L){}
    Worker(const string & s, long n) : fullname(s), id(n){}
    virtual ~Worker() = 0;
    virtual void Set();
    virtual void show() const;
};

/* 第一个从Worker继承的类 */
class Waiter : virtual public Worker
{
private:
    int panache;
public:
    Waiter() : Worker(), panache(0){}
    Waiter(const string & s, long n, int p = 0) : Worker(s, n), panache(p){}
    Waiter(const Worker & wk, int p = 0) : Worker(wk), panache(p){}
    void Set();
    void Show() const;
};

/* 第二个从Worker继承的类 */
class Singer : virtual public Worker
{
protected:
    enum {other, alto, contralto, soprano, bass, baritone, tonor};
    enum {Vtypes = 7};
private:
    static char * pv[Vtypes];
    int voice;
public:
    Singer() : Worker(), voice(other){}
    Singer(const string & s, long n, int v = other) : Worker(s, n), voice(v){}
    Singer(const Worker & wk, int v = other) : Worker(wk), voice(v){}
    void Set();
    void Show() const;
};

class SingingWaiter : public Singer, public Waiter
{
public:
    void Set(){}
};

int main()
{
    SingingWaiter s;
    Worker *p = &s;
    return 1;
}
