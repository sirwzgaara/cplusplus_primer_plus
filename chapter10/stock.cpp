
#include <iostream>
#include "stock.h"

using namespace std;

Stock::Stock(const string & co, long n, double pr)
{
    company = co;
    if (n < 0)
        shares = 0;
    else
        shares = n;
    share_val = pr;
    set_tot();
}

void Stock::acquire(const string & co, long n, double pr)
{
    company = co;
    if (n < 0)
        shares = 0;
    else
        shares = n;
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price)
{
    if (num > 0)
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if (num < 0)
        cout << "invalid" << endl;
    else if (num > shares)
        cout << "invalid" << endl;
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    cout << "Company: " << company << endl
        << "shares: " << shares << endl
        << "share price: " << share_val << endl
        << "total worth: " << total_val << endl;
}
