#include <iostream>
#include "../include/rectangleType.h"

using namespace std;

// Methods Definitions
void rectangleType::setDimension(double l, double w)
{
    if (l >= 0)
        length = l;
    else
        length = 0;
    if (w >= 0)
        width = w;
    else
        width = 0;
}

double rectangleType::getLength() const
{
    return length;
}
double rectangleType::getWidth() const
{
    return width;
}
double rectangleType::area() const
{
    return length * width;
}
double rectangleType::perimeter() const
{
    return 2 * (length + width);
}
void rectangleType::print() const
{
    cout << "Length = " << length << "; Width = " << width;
}

rectangleType rectangleType::operator+(const rectangleType &rectangle) const
{
    rectangleType temp;

    temp.length = length + rectangle.length;
    temp.width = width + rectangle.width;

    return temp;
}

rectangleType rectangleType::operator*(const rectangleType &rectangle) const
{
    rectangleType temp;

    temp.length = length * rectangle.length;
    temp.width = width * rectangle.width;

    return temp;
}

bool rectangleType::operator==(const rectangleType &rectancle) const
{
    return (length == rectancle.length && width == rectancle.width);
}

bool rectangleType::operator!=(const rectangleType &rectancle) const
{
    return (length != rectancle.length || width != rectancle.width);
}

rectangleType::rectangleType(double l, double w)
{
    setDimension(l, w);
}
rectangleType::rectangleType()
{
    length = 0;
    width = 0;
}

ostream &operator<<(ostream &osObject, const rectangleType &rectangle)
{
    osObject << "Length = " << rectangle.length
             << "; Width = " << rectangle.width;

    return osObject;
}

istream &operator>>(istream &isObject, rectangleType &rectangle)
{
    isObject >> rectangle.length >> rectangle.width;

    return isObject;
}
