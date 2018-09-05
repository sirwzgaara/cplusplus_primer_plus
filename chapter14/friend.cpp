
#include <iostream>
using namespace std;

//#define FIRST
//define SECOND
#define THIRD

/* 非模板友元 */

#ifdef FIRST

template <typename T>
class HasFriend
{
private:
    T item;
    static int ct;
public:
    HasFriend(const T & i) : item(i){ct++;}
    ~HasFriend(){ct;;}
friend void counts();
friend void reports(HasFriend<T> &);
};

template <typename T>
int HasFriend<T>::ct = 0;

void counts()
{
    cout << HasFriend<int>::ct << endl;
    cout << HasFriend<double>::ct << endl;
}

#endif


/* 约束模板友元 */

#ifdef SECOND

template <typename T>
void counts();
template <typename T>
void reports(T &);

template <typename T>
class HasFriend
{
private:
    T item;
    static int ct;
public:
    HasFriend(const T & i) : item(i){ct++;}
    ~HasFriend(){ct--;}
friend void counts();
friend void reports<>(HasFriend<T> &);
};

template <typename T>
int HasFriend<T>::ct = 0;

template <typename T>
void counts()
{
    cout << sizeof(HasFriend<T>) << endl;
    cout << HasFriend<T>::ct << endl;
}

template <typename T>
void reports(T & hf)
{
    cout << hf.item << endl;
}

#endif

#ifdef THIRD

template <typename T>
class HasFriend
{
private:
    T item;
public:
    HasFriend(const T & i) : item(i){}
    ~HasFriend(){}
    template <typename U, typename V>
    friend void show(U u, V v);
};

template <typename U, typename V>
void show(U u, V v)
{
    cout << u.item << endl;
    cout << v.item << endl;
};


#endif

int main()
{
    HasFriend<int> hfi1(10);
    HasFriend<int> hfi2(20);
    show(hfi1, hfi2);
    return 1;
}
