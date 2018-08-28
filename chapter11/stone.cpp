
#include <iostream>
using namespace std;

class Stone
{
private:
    enum {Lbs_per_stn = 14};
    int stone;
    double pds_left;
    double pounds;
public:
    Stone(double lbs);
    Stone(int stn, double lbs);
    Stone(){}
    ~Stone(){}
    void show_lbs() const;
    void show_stn() const;
    operator double() const;
    operator int() const;
};

Stone::Stone(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stone::Stone(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn;
}

void Stone::show_lbs() const
{
    
}

void Stone::show_stn() const
{

}

Stone::operator int() const
{
    return int(pounds + 0.5);
}

Stone::operator double() const
{
    return pounds;
}

int main()
{
    return 1;
}
