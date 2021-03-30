#include "Complex.h"

// Friend function s-- implemented OUTSIDE of the class
std::ostream& operator<<(std::ostream& out, const Complex& other)
{
    out << "(" << other.mReal << "," << other.mImaginary << ")";

    return out;
}

Complex operator+(const Complex& other, double val)
{
    return Complex(other.mReal + val, other.mImaginary);
}
   
Complex operator+(double val, const Complex& other)
{
    return Complex(other.mReal + val, other.mImaginary);
}


Complex::Complex() : 
    mReal(0.0), 
    mImaginary(0.0)
{

}

Complex::Complex(double r, double i) : 
    mReal(r), 
    mImaginary(i)
{
    
}

Complex::Complex(const Complex& other)
{
    mReal = other.mReal;
    mImaginary = other.mImaginary;
}

const Complex& Complex::operator=(const Complex& other)
{
    this->mReal = other.mReal;
    this->mImaginary = other.mImaginary;

    return *this;
}

Complex Complex::operator+(const Complex& other)
{
    return Complex(this->mReal + other.mReal, this->mImaginary + other.mImaginary);
}



Complex Complex::operator-(const Complex& other)
{
    return Complex(this->mReal - other.mReal, this->mImaginary - other.mImaginary);
}

bool Complex::operator==(const Complex& other) const
{
    return ( (this->mReal == other.mReal) && (this->mImaginary == other.mImaginary) );
}

bool Complex::operator!=(const Complex& other) const
{
    return !(this->operator==(other));
}