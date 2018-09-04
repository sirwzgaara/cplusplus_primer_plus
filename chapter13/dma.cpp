
#include <iostream>
#include <cstring>
using namespace std;

class baseDMA
{
private:
    char * label;
    int rating;
public:
    baseDMA(const char * = "NULL", int = 0);
    baseDMA(const baseDMA &);
    ~baseDMA();
    baseDMA & operator=(const baseDMA &);
friend ostream & operator<<(ostream & os, const baseDMA & t);
};

baseDMA::baseDMA(const char * l, int r)
{
    label = new char[strlen(l) + 1];
    strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA & t)
{
    label = new char[strlen(t.label) + 1];
    strcpy(label, t.label);
    rating = t.rating;
}

baseDMA::~baseDMA()
{
    delete [] label;
}

baseDMA & baseDMA::operator=(const baseDMA & t)
{
    if (this != &t)
    {
        baseDMA local(t);
        char * temp = local.label;
        local.label = label;
        label = temp;
        rating = local.rating;
    }
    return * this;
}

ostream & operator<<(ostream & os, const baseDMA & t)
{
    os << t.label << endl;
    os << t.rating << endl;
    return os;
}

class hasDMA : public baseDMA
{
private:
    char * style;
public:
    hasDMA(const char * = "NULL");
    hasDMA(const baseDMA &, const char * = "NULL");
    hasDMA(const hasDMA &);
    ~hasDMA();
    hasDMA & operator=(const hasDMA &);
friend ostream & operator<<(ostream & os, const hasDMA & t);
};

hasDMA::hasDMA(const char * s)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const baseDMA & t, const char * s) : baseDMA(t)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & t) : baseDMA(t)
{
    style = new char[strlen(t.style) + 1];
    strcpy(style, t.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & t)
{
    if (this != &t)
    {
        baseDMA::operator=(t);
        hasDMA local(t);
        char * temp = local.style;
        local.style = style;
        style = temp;
    }
    return * this;
}

ostream & operator<<(ostream & os, const hasDMA & t)
{
    os << (baseDMA &)t;
    os << t.style << endl;
    return os;
}

int main()
{
    hasDMA t1;
    hasDMA t2;
    t2 = t1;
    hasDMA t3 = t1;
    return 1;
}
