# include <iostream>
using namespace std;

class Complex
{
public:
    double real;
    double virtl;
    Complex(double r, double v):real(r), virtl(v){}
    Complex operator+(const Complex &a);
    Complex operator-(const Complex &a);
    void toString();
};

Complex Complex::operator + (const Complex &a)
{
    Complex tmp(0,0);
    tmp.real = this->real+a.real;
    tmp.virtl = this->virtl + a.virtl;
    return tmp;
}

Complex Complex::operator-(const Complex &a)
{
    Complex tmp(0, 0);
    tmp.real = this->real - a.real;
    tmp.virtl = this->virtl - a.virtl;
    return tmp;
}

void Complex::toString()
{
    cout << real << " + " << virtl << "i" << " ";
}