
#include <iostream>
using namespace std;

class Stonewt
{
private:
    enum {Lbs_per_stn = 14};
    int stone;
    double pds_left;
    double pounds;
public:
    explicit Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
    explicit operator double() const;
    operator int() const;
};

Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int (lbs) / Lbs_per_stn + lbs - int (lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()
{

}

void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds" << endl;
}

void Stonewt::show_lbs() const
{
    cout << pounds << " pounds" << endl;
}

Stonewt::operator double() const
{
    return pounds;
}

Stonewt::operator int() const
{
    return int (pounds + 0.5);
}

void func()
{
    Stonewt mycat;
    mycat = (Stonewt)19.6;
    int n = mycat;
}

int main()
{
    func();
    return 1;
}
