
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

/* 构造函数使用初始化列表，string类成员调用string类的构造函数 */
TableTennisPlayer::TableTennisPlayer(const string & fn, const string &ln, bool ht) :
    firstname(fn), lastname(ln), hasTable(ht)
{
}

void TableTennisPlayer::Name() const
{
    cout << lastname << ", " << firstname << endl;
}

//公有继承自TableTennisPlayer的派生类
class RatedPlayer : public TableTennisPlayer
{
private:
    /* 新增数据成员 */
    unsigned int rating;
public:
    /* 派生类需要自己的构造函数，要负责初始化基类数据成员 */
    RatedPlayer(unsigned int = 0, const string & = "none", const string & = "none", bool = false);
    RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
    /* 新增方法 */
    unsigned int Rating() const {return rating;}
    void ResetRating(unsigned int r){rating = r;}
};

/* 派生类不能访问基类的private成员，需要通过基类构造函数 */
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
