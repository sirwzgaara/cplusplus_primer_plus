
#include <iostream>
#include <string>

using namespace std;
const int BUF = 512;

class Test
{
private:
    string words;
    int number;
public:
    Test(const string & s = "Test", int n = 0)
    {
        words = s;
        number = n;
        cout << words << " created" << endl;
    }
    ~Test(){cout << words << " destoryed" << endl;}
    void Show() const{cout << words << ", " << number << endl;}
};

int main()
{
    char * buffer = new char[BUF];
    Test *p1, *p2;
    p1 = new (buffer) Test;
    p2 = new Test("Heap1", 20);
    cout << p1 << ": ";
    p1->Show();
    cout << p2 << ": ";
    p2->Show();

    Test *p3, *p4;
    p3 = new (buffer) Test("bad idea", 6);
    p4 = new Test("Heap2", 10);
    cout << p3 << ": ";
    p3->Show();
    cout << p4 << ": ";
    p4->Show();
    delete p2;
    delete p4;
    delete [] buffer;
    cout << "Done\n";

    return 1;
}
