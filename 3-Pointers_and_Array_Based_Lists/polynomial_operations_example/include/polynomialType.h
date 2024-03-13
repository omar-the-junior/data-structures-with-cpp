#ifndef H_POLYNOMIALTYPE
#define H_POLYNOMIALTYPE

#include <iostream>
#include "./arrayListType.h"

using namespace std;
class polynomialType : public arrayListType<double>
{
    friend ostream &operator<<(ostream &, const polynomialType &);
    friend istream &operator>>(istream &, polynomialType &);

public:
    polynomialType operator+(const polynomialType &);
    polynomialType operator-(const polynomialType &);
    polynomialType operator*(const polynomialType &);

    double operator()(double x);
    // Overloads the operator () to evaluate the polynomial at a given point
    // Postcondition: the value of the polynomial at x is calculated and returned

    polynomialType(int size = 100);

    int min(int x, int y) const;
    int max(int x, int y) const;
};
#endif