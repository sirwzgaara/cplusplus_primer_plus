
#include <iostream>
#include <string>
using namespace std;

class Brass
{
private:
    string fullName;
    long acctNum;
    double balance;
public:
    Brass(const string & s = "Nullbody", long an = -1, double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double Balance() const;
    virtual void ViewAcct() const;
    virtual ~Brass(){}
};

class BrassPlus : public Brass
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const string & s = "Nullbody", long an = -1, double bal = 0.0,
            double ml = 500, double r = 0.11125);
    BrassPlus(const Brass & ba, double ml = 500, double r = 0.11125);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m){maxLoan = m;}
    void ResetRate(double r){rate = r;}
    void ResetOwes(){owesBank = 0;}
};

/* 调整格式相关函数 */
typedef ios_base::fmtflags format;
typedef streamsize precis;
format setFormat();
void restore(format f, precis p);

Brass::Brass(const string & s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt)
{
    if (amt < 0)
        cout << "negative deposit not allowed" << endl;
    else
        balance += amt;
}

void Brass::Withdraw(double amt)
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if (amt < 0)
        cout << "withdraw amount must be positive" << endl;
    else if (amt <= balance)
        balance -= amt;
    else
        cout << "withdraw amount " << amt << "exceeds balance" << endl;
    restore(initialState, prec);
}

double Brass::Balance() const
{
    return balance;
}

void Brass::ViewAcct() const
{
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout << "Clinet: " << fullName << endl;
    cout << "Account NUmber: " << acctNum << endl;
    cout << "Balance: " << balance << endl;
    restore(initialState, prec);
}

BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r) : Brass(ba)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : Brass(ba)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    Brass::ViewAcct();
    cout << "Maxinum loan " << maxLoan << endl;
    cout << "Owed to bank " << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << endl;
    restore(initialState, prec);
}

void BrassPlus::WithDraw(double amt)
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = Balance();
    if (amt <= bal)
        Brass::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance " << advance << endl;
        cout << "Finance charge " << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else
        cout << "Credit limit exceed, Transaction cancelled" << endl;
    restore(initialState, prec);
}

format setFormat()
{
    return setf(ios_base::fixed, ios_base::floatfield);
}

void restore(format f, precis p)
{
    setf(f, ios_base::floatfiled);
    cout.precision(p);
}

int main()
{
    return 1;
}
