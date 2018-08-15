
#include <iostream>
#include <string>
using namespace std;

class TableTennisPlayer
{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string & = "none", const string & = "none", bool = false);
    void Name() const;
    bool HasTable() const {return hasTable;}
    void ResetTable(bool v){hasTable = v;}
};

TableTennisPlayer::TableTennisPlayer(const string & fn, const string &ln, bool ht) :
    firstname(fn), lastname(ln), hasTable(ht)
{
}

void TableTennisPlayer::Name() const
{
    cout << lastname << ", " << firstname << endl;
}

class RatedPlayer : public TableTennisPlayer
{
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int = 0, const string & = "none", const string & = "none", bool = false);
    RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
    unsigned int Rating() const {return rating;}
    void ResetRating(unsigned int r){rating = r;}
};

RatedPlayer::RatedPlayer(unsigned int r, const string & fn, const string & ln, bool ht) :
    TableTennisPlayer(fn, ln, ht)
{
    rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp) :
    rating(r), TableTennisPlayer(tp)
{
}

int main()
{
    return 1;
}
