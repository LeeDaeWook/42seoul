#include "Point.hpp"

float getTriangleSize( Point const a, Point const b, Point const c)
{
    return (a.getX().toFloat() - c.getX().toFloat()) * (b.getY().toFloat() - c.getY().toFloat()) - (b.getX().toFloat() - c.getX().toFloat()) * (a.getY().toFloat() - c.getY().toFloat());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{    

    float t1 = getTriangleSize(a, b, point);
    float t2 = getTriangleSize(b, c, point);
    float t3 = getTriangleSize(c, a, point);
    float whole = getTriangleSize(a, b, c);

    if (t1 > 0 && t2 > 0 && t3 > 0 && t1 + t2 + t3 == whole)
        return true;
    else
        return false;
}