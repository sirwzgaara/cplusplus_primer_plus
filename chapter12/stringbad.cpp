
#include <iostream>
#include <cstring>
using namespace std;

class Stringbad
{
private:
    char * str;
    int len;
    static int num_strings;
public:
    Stringbad(const char *);
    Stringbad();
    Stringbad(const Stringbad &);
    ~Stringbad();
    Stringbad & operator=(const Stringbad &);
friend ostream & operator<<(ostream & os, const Stringbad & st);
};

//初始化类中static的方式，不是const，只能在外面这样初始化
int Stringbad::num_strings = 0;

Stringbad::Stringbad(const char *s)
{
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    num_strings++;
    cout << num_strings << " : " << str << " by noraml " << endl;
}

Stringbad::Stringbad()
{
    len = 4;
    str = new char[4];
    strcpy(str, "C++");
    num_strings++;
    cout << num_strings << " : " << str << " by default " << endl;
}

Stringbad::Stringbad(const Stringbad & st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    cout << num_strings << " : " << str << " by copy " << endl;
}

Stringbad::~Stringbad()
{
    cout << str << " deleted " << endl;
    --num_strings;
    cout << num_strings << " left" << endl;
    delete [] str;
}

Stringbad & Stringbad::operator=(const Stringbad & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    
    return *this;
}

ostream & operator<<(ostream & os, const Stringbad & st)
{
    os << st.str;
    return os;
}

void callme1(Stringbad &rsb)
{
    cout << "callme1" << endl;
}

void callme2(Stringbad sb)
{
    cout << "callme2" << endl;
}

int main()
{
    Stringbad headline1("qqqq qq");
    Stringbad headline2 = headline1;
    callme2(headline2);
    headline2 = headline1;
    return 1;
}
