
#ifndef _STOCK_H
#define _SOTCK_H
#endif

#include <string>
using namespace std;

class Stock
{
private:
    int i;
    int j;
public:
    Stock();
    Stock(int, int = 0);
    ~Stock();
    void show() const;
};
