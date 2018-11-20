
#ifndef _STOCK_H
#define _SOTCK_H
#endif

#include <string>
using namespace std;

class Stock
{
private:
    string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot(){total_val = share_val * shares;}
public:
    Stock(const string & co, long n, double pr);
    void acquire(const string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};
