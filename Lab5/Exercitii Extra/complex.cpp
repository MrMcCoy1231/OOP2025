#include "complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}


Complex operator+(const Complex& l, const Complex& r)
{
    Complex c(l.real() + r.real(), l.imag() + r.imag());
    return c;
}
Complex operator+(const Complex& l, double r)
{
    Complex c(l.real() + r, l.imag());
    return c;
}
Complex operator+(double l, const Complex& r)
{
    Complex c(l + r.real(), r.imag());
    return c;
}

Complex operator-(const Complex& obj)
{
    Complex c(-obj.real(), -obj.imag());
    return c;
}

Complex operator-(const Complex& l, const Complex& r)
{
    Complex c(l.real() - r.real(), l.imag() - r.imag());
    return c;

}
Complex operator-(const Complex& l, double r)
{
    Complex c(l.real() - r, l.imag());
    return c;

}
Complex operator-(double l, const Complex& r)
{
    Complex c(l - r.real(), r.imag());
    return c;

}

Complex operator*(const Complex& l, const Complex& r)
{
    Complex c(l.real() * r.real() - l.imag() * r.imag(), l.real() * r.imag() + l.imag() * r.real());
    return c;

}
Complex operator*(const Complex& l, double r)
{
    Complex c(l.real() * r, l.imag() * r);
    return c;

}
Complex operator*(double l, const Complex& r)
{
    Complex c(l * r.real(), l * r.imag());
    return c;

}


bool operator==(const Complex& l, const Complex& r)
{
    return (l.real() == r.real() && l.imag() == r.imag());
}

bool operator==(const Complex& l, double r)
{
    return (l.real() == r && l.imag() == 0);
}

bool operator==(double r, const Complex& l)
{
    return (r == l.real() && 0 == l.imag());
}

bool operator!=(const Complex& l, const Complex& r)
{
    return !(l == r);

}

bool operator!=(const Complex& l, double r)
{
    return !(l == r);
}

bool operator!=(double l, const Complex& r)
{
    return !(l == r);
}

std::ostream& operator<<(std::ostream& cout, const Complex& complex)
{
    cout << complex.real() << " " << complex.imag()<<"i";
    
    return cout;
}



Complex& Complex :: operator()(double real, double imag)
{
    this->real_data = real;
    this->imag_data = imag;

    return *this;
}


Complex& Complex :: operator++()  //forma prefixata
{
    real_data++;
    return *this;
}
Complex Complex :: operator++(int)  //forma postfixata
{   
    Complex aux = *this;
    ++(*this);
    return aux;
}

Complex& Complex :: operator--()  //forma prefixata
{
    real_data--;
    return *this;

}

Complex Complex :: operator--(int)   //forma postfixata
{   
    Complex aux = *this;
    --(*this);
    return aux;

}


