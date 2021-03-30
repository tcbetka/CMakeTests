#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
private:
    double mReal;
    double mImaginary;

public:
    Complex();
    Complex(double r, double i);
    ~Complex() = default;

    // Copy ctor
    Complex(const Complex& other);

    // Copy assignment operator
    const Complex& operator=(const Complex& other);

    // Overloaded operator+ needs to return a Complex object (not a ref)
    Complex operator+(const Complex& other);

    // Overloaded operator- needs to return a Complex object (not a ref)
    Complex operator-(const Complex& other);

    // Overloaded operator==
    bool operator==(const Complex& other) const;

    // Overloaded operator!=
    bool operator!=(const Complex& other) const;

    // Friend functions here
    friend std::ostream& operator<<(std::ostream& out, const Complex& other);
    friend Complex operator+(const Complex& other, double val);
    friend Complex operator+(double val, const Complex& other);
};


#endif // COMPLEX_H