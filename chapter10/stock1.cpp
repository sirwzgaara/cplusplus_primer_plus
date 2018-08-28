
#include <iostream>
#include "stock.h"

using namespace std;

Stock::Stock()
{
    cout << "Stock::Stock()" << endl;
}

Stock::Stock(int i, int j)
{
    cout << "Stock::Stock(int i, int j)" << endl;
}

Stock::~Stock()
{
    cout << "~Stock()" << endl;
}

void Stock::show() const
{
    cout << "show()" << endl;
}
