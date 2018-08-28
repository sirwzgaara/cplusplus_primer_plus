
#include <iostream>
using namespace std;

typedef unsigned long Item;

class Stack
{
private:
    enum {MAX = 10};
    Item items[MAX];
    int top;
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
};

Stack::Stack()
{
    top = 0;
}

bool Stack::isempty() const
{
    return 0 == top;
}

bool Stack::isfull() const
{
    return MAX == top;
}

bool Stack::push(const Item & item)
{
    if (isfull())
        return false;
    items[top++] = item;
    return true;
}

bool Stack::pop(Item & item)
{

    if (isempty())
        return false;
    item = items[--top];
    return true;
}

int main()
{
    return 1;
}
