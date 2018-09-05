
#include <iostream>
using namespace std;

template <typename T>
class beta
{
private:
    template <typename V>
    class hold
    {
    private:
        V val;
    public:
        hold(V v = 0) : val(v){}
        void show() const {cout << val << endl;}
        V Value() const {return val;}
    };
    hold<T> q;      //一个泛型成员
    hold<int> n;    //一个具体化成员
public:
    beta(T t, int i) : q(t), n(i){}
    template <typename U>
    U blab(U u, T t);
    void Show() const {q.show();n.show();}
};

template <typename T>
    template <typename U>
    U beta<T>::blab(U u, T t)
    {
        return (n.Value() + q.Value()) * u / t;
    }

void func()
{
    beta<double> guy(3.5, 3);
    guy.Show();
    cout << guy.blab(10, 2.3) << endl;
}

int main()
{
    func();
    return 1;
}
