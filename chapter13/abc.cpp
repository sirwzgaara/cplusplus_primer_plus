
#include <string>
#include <iostream>
using namespace std;

//这是一个纯虚基类
class abc
{
private:
    int i;
public:
    abc(){}
    virtual void la()=0;
    /* 定义为纯虚的函数不需要提供定义 */
    virtual ~abc()= 0;
};

/* 定义为纯虚的函数也可以提供定义，通过类作用域引用 */
void abc::la()
{

}

class a : public abc
{
public:
    void lala(){abc::la();}
};

void func()
{
    //abc tmp;
}

int main()
{
    func();
    return 1;
}
