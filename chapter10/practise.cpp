
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/* practise1 */
class Account
{
private:
    string name;
    string number;
    double money;
public:
    Account()
    {
        name = "none";
        number = "none";
        money = 0.0;
    }
    Account(string _name, string _number, double _money) : name(_name), number
            (_number), money(_money){}
    void Show() const;
    bool In(double & _money);
    bool Out(double & money);
};

void Account::Show() const
{
    cout << "name is " << name << ", number is " << number << ", money is "
        << money << endl;
}

bool Account::In(double & _money)
{
    if (0 < _money)
        return false;
    money += _money;
    return true;
}

bool Account::Out(double & _money)
{
    if (money - _money < 0)
        return false;
    money -= _money;
    return true;
}

/* practise2 */
class Person
{
private:
    static const int LIMIT = 25;
    string lname;
    char fname[LIMIT];
public:
    Person()
    {
        lname = "";
        fname[0] = '\0';
    }
    Person(const string & ln, const char * fn = "Heyyou");
    void Show() const{}
    void FormalShow() const{}
};

Person::Person(const string & ln, const char * fn)
{
    lname = ln;
    strncpy(fname, fn, LIMIT);
}

int main()
{
    return 1;
}
