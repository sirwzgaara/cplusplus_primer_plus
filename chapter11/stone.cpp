
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
    explicit Stonewt(double lbs);    //通过加explicit防止隐式类型转换
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt(){}
    void show_lbs() const;
    void show_stn() const;
    /* 转换函数 */
    explicit operator double() const;
    operator int() const;
};

/* 此函数存在让Stonewt mycat; mycat = 19.6这种赋值成为可能 */
Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
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
    stone = pds_left = pounds = 0;
}

void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}

Stonewt::operator int() const
{
    /* 一个四舍五入的方法 */
    return int(pounds + 0.5);
}

Stonewt::operator double() const
{
    return pounds;
}

int main()
{
    Stonewt t(19.6);
    double n = t;
    return 1;
}
