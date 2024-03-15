#ifndef H_complexNumber
#define H_complexNumber

#include <iostream>

using namespace std;

class complexType
{
    friend ostream &operator<<(ostream &, const complexType &);
    friend istream &operator>>(istream &, complexType &);

private:
    double realPart;
    double imaginaryPart;

public:
    void setComplex(const double &real, const double &imag);
    void getComplex(double &real, double &imag) const;

    complexType(double real = 0, double imag = 0);
    complexType operator+(const complexType &otherComplex) const;
    complexType operator*(const complexType &otherComplex) const;
    bool operator==(const complexType &otherComplex) const;
};

ostream &operator<<(ostream &osObject, const complexType &complex)
{
    osObject << "(" << complex.realPart << ", " << complex.imaginaryPart << ")";
    return osObject;
}

istream &operator>>(istream &isObject, complexType &complex)
{
    char ch;

    isObject >> ch;
    isObject >> complex.realPart;
    isObject >> ch; // read the comma
    isObject >> complex.imaginaryPart;
    isObject >> ch; // read the right parenthesis

    return isObject;
}

bool complexType::operator==(const complexType &otherComplex) const
{
    return (realPart == otherComplex.realPart &&
            imaginaryPart == otherComplex.imaginaryPart);
}

complexType::complexType(double real, double imag)
{
    realPart = real;
    imaginaryPart = imag;
}

void complexType::setComplex(const double &real, const double &imag)
{
    realPart = real;
    imaginaryPart = imag;
}

void complexType::getComplex(double &real, double &imag) const
{
    real = realPart;
    imag = imaginaryPart;
}

complexType complexType::operator+(const complexType &otherComplex) const
{
    complexType temp;
    temp.realPart = realPart + otherComplex.realPart;
    temp.imaginaryPart = imaginaryPart + otherComplex.imaginaryPart;

    return temp;
}

complexType complexType::operator*(const complexType &otherComplex) const
{
    complexType temp;

    temp.realPart = (realPart * otherComplex.realPart) - (imaginaryPart * otherComplex.imaginaryPart);

    temp.imaginaryPart = (realPart * otherComplex.imaginaryPart) + (imaginaryPart * otherComplex.realPart);

    return temp;
}

#endif