
#include <iostream>
using namespace std;

class baseDMA
{
private:
    char * label;
    int rating;
public:
    baseDMA(const char * = "NULL", int = 0);
    baseDMA(const baseDMA &);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA &);
};

class lasksDMA : public baseDMA
{
private:
    char * style;
};

int main()
{
    return 1;
}
