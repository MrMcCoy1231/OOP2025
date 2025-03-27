#pragma once

#include <ostream>

class Complex {
private:
    double real_data;
    double imag_data;

public:
    Complex();
    Complex(double real, double imag);

    bool is_real() const;

    double real() const;
    double imag() const;
    double abs() const;
    Complex conjugate() const;

    Complex& operator()(double real, double imag);

    Complex& operator++();
    Complex operator++(int);

    Complex& operator--();
    Complex operator--(int);
    
};

Complex operator+(const Complex& l, const Complex& r);
Complex operator+(const Complex& l, double r);
Complex operator+(double l, const Complex& r);

Complex operator-(const Complex& l, const Complex& r);
Complex operator-(const Complex& l, double r);
Complex operator-(double l, const Complex& r);

Complex operator*(const Complex& l, const Complex& r);
Complex operator*(const Complex& l, double r);
Complex operator*(double l, const Complex& r);

Complex operator-(const Complex& obj);

bool operator==(const Complex& l, const Complex& r);
bool operator==(const Complex& l, double r);
bool operator==(double r, const Complex& l);
bool operator!=(const Complex& l, const Complex& r);

std::ostream& operator<<(std::ostream& cout, const Complex& complex);
