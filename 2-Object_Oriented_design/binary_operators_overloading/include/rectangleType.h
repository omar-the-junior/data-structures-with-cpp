// rectangleType.h
#include <iostream>

using namespace std;

#ifndef RECTANGLETYPE_H
#define RECTANGLETYPE_H

class rectangleType
{
    friend ostream &operator<<(ostream &, const rectangleType &);
    friend istream &operator>>(istream &, rectangleType &);

public:
    // Method declarations
    void setDimension(double l, double w);

    double getLength() const;
    double getWidth() const;
    double area() const;
    double perimeter() const;
    void print() const;

    rectangleType operator+(const rectangleType &) const;
    rectangleType operator*(const rectangleType &) const;

    bool operator==(const rectangleType &) const;
    bool operator!=(const rectangleType &) const;

    rectangleType();
    rectangleType(double l, double w);

private:
    double length;
    double width;
};
#endif // RECTANGLETYPE_H