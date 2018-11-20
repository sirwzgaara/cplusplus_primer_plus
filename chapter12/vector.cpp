
#include <iostream>
#include <cmath>
using namespace std;

/* 使用命名空间 */
namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode{RECT, POL};
    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;
        /* 私有方法 */
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const {return x;}
        double yval() const {return y;}
        double magval() const {return mag;}
        double angval() const {return ang;}
        void polar_mode();
        void rect_mode();
        /* 重载运算符 */
        Vector operator+(const Vector & v) const;
        Vector operator-(const Vector & v) const;
        Vector operator-() const;           //这个是加负号
        Vector operator*(double n) const;
        /* 友元函数 */
        friend Vector operator*(double n, const Vector & v);
        friend ostream & operator<<(ostream & os, const Vector & v);
    };
}

namespace VECTOR
{
    const double Rad_to_deg = 45.0 / atan(1.0);
    /* 私用方法实现 */
    void Vector::set_mag()
    {
        mag = sqrt(x * x + y * y);
    }

    void Vector::set_ang()
    {
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);
    }

    void Vector::set_x()
    {
        x = mag * cos(ang);
    }

    void Vector::set_y()
    {
        y = mag * sin(ang);
    }

    /* 公有方法实现 */
    Vector::Vector()
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (RECT == form)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (POL == form)
        {
            mag = n1;
            ang = n2;
            set_x();
            set_y();
        }
        else
        {
            cout << "invalid" << endl;
            x = y = mag = ang = 0.0;
        }
    }

    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (RECT == form)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (POL == form)
        {
            mag = n1;
            ang = n2;
            set_x();
            set_y();
        }
        else
        {
            cout << "invalid" << endl;
            x = y = mag = ang = 0.0;
        }
    }

    Vector::~Vector()
    {
        
    }

    void Vector::polar_mode()
    {
        mode = POL;
    }

    void Vector::rect_mode()
    {
        mode = RECT;
    }

    Vector Vector::operator+(const Vector & v) const
    {
        /* 利用构造函数 */
        return Vector(x + v.x, y + v.y);
    }

    Vector Vector::operator-(const Vector & v) const
    {
        return Vector(x - v.x, y - v.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(x * n, y * n);
    }

    Vector operator*(double n, const Vector & v)
    {
        return v * n;
    }

    ostream & operator<<(ostream & os, const Vector & v)
    {
        if (v.mode == Vector::RECT)
            os << "(x, y) = (" << v.x << ", " << v.y << ")" << endl;
        else if (v.mode == Vector::POL)
            os << "(mag, ang) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")" << endl;
        else
            os << "invalid" << endl;
        return os;
    }
}

int main()
{
    VECTOR::Vector t(20.0, 30.0, VECTOR::Vector::Mode(2));
    return 1;
}
