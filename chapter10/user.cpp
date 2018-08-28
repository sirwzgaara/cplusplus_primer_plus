
#include <iostream>
#include "stock.h"

using namespace std;

int main()
{
    cout << "-----------------" << endl;
    Stock stock1(1, 2);
    Stock stock2 = Stock(1, 2);
    /* 这一步是单纯的赋值，没有构造或者析构的调用 */
    stock2 = stock1;
    cout << "-----------------" << endl;
    /* 构造一个临时对象，赋值给stock1，然后析构这个临时对象 */
    stock1 = Stock(1, 2);
    cout << "-----------------" << endl;
    return 0;
}
