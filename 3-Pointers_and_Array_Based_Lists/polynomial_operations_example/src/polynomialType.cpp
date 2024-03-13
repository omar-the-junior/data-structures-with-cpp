#include <iostream>
#include <cmath>
#include "../include/polynomialType.h"
#include "./arrayListType.cpp"
using namespace std;

polynomialType::polynomialType(int size) : arrayListType<double>(size)
{
    length = size;

    for (int i = 0; i < size; i++)
        list[i] = 0;
}

double polynomialType::operator()(double x)
{
    double value = 0.0;

    for (int i = 0; i < length; i++)
        value += list[i] * pow(x, i);

    return value;
}

polynomialType polynomialType::operator+(const polynomialType &right)
{
    int size = max(length, right.length);

    polynomialType temp(size);

    for (int i = 0; i < min(length, right.length); i++)
        temp.list[i] = list[i] + right.list[i];

    if (size == length)
        for (int i = min(length, right.length); i < length; i++)
            temp.list[i] = list[i];

    else
        for (int i = min(length, right.length); i < right.length; i++)
            temp.list[i] = right.list[i];
    return temp;
}

polynomialType polynomialType::operator-(const polynomialType &right)
{
    int size = max(length, right.length);

    polynomialType temp(size);

    for (int i = 0; i < min(length, right.length); i++)
        temp.list[i] = list[i] - right.list[i];

    if (size == length)
        for (int i = min(length, right.length); i < length; i++)
            temp.list[i] = list[i];
    else
        for (int i = min(length, right.length); i < right.length; i++)
            temp.list[i] = list[i];

    return temp;
}

int polynomialType::min(int x, int y) const
{
    return (x <= y) ? x : y;
}

int polynomialType::max(int x, int y) const
{
    return (x >= y) ? x : y;
}

ostream &operator<<(ostream &os, const polynomialType &p)
{
    int indexFirstNonZeroCoeff = 0;

    for (int i = 0; i < p.length; i++)
    {
        if (p.list[i] != 0.0)
        {
            indexFirstNonZeroCoeff = i;
            break;
        }
    }

    if (indexFirstNonZeroCoeff < p.length)
    {
        if (indexFirstNonZeroCoeff == 0)
            os << p.list[indexFirstNonZeroCoeff] << " ";
        else
            os << p.list[indexFirstNonZeroCoeff] << "x^" << indexFirstNonZeroCoeff << " ";

        for (int i = indexFirstNonZeroCoeff + 1; i < p.length; i++)
        {
            if (p.list[i] != 0.0)
            {
                if (p.list[i] >= 0.0)
                    os << "+ " << p.list[i] << "x^" << i << " ";
                else
                    os << "- " << -p.list[i] << "x^" << i << " ";
            }
        }
    }
    else
        os << "0";
    return os;
}

istream &operator>>(istream &is, polynomialType &p)
{
    cout << "The degree of this polynomial is: "
         << p.length - 1 << endl;

    for (int i = 0; i < p.length; i++)
    {
        cout << "Enter the coefficient of x^" << i << ": ";
        is >> p.list[i];
    }

    return is;
}