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

    // std::cout << t1 << std::endl;
    // std::cout << t2 << std::endl;
    // std::cout << t3 << std::endl;
    // std::cout << whole << std::endl;

    if (t1 > 0 && t2 > 0 && t3 > 0 && t1 + t2 + t3 == whole)
        return true;
    else
        return false;
}

// bool bsp( Point const a, Point const b, Point const c, Point const point)
// {
//     float alpha = ((b.getY().toFloat() - c.getY().toFloat())*(point.getX().toFloat() - c.getX().toFloat()) + (c.getX().toFloat() - b.getX().toFloat())*(point.getY().toFloat() - c.getY().toFloat())) / 
// 				((b.getY().toFloat() - c.getY().toFloat())*(a.getX().toFloat() - c.getX().toFloat()) + (c.getX().toFloat() - b.getX().toFloat())*(a.getY().toFloat() - c.getY().toFloat())); 
//     float beta = ((c.getY().toFloat() - a.getY().toFloat())*(point.getX().toFloat() - c.getX().toFloat()) + (a.getX().toFloat() - c.getX().toFloat())*(point.getY().toFloat() - c.getY().toFloat())) / 
// 				((b.getY().toFloat() - c.getY().toFloat())*(a.getX().toFloat() - c.getX().toFloat()) + (c.getX().toFloat() - b.getX().toFloat())*(a.getY().toFloat() - c.getY().toFloat())); 
//     float gamma = 1.0f - alpha - beta;
//     if (alpha > 0 && beta > 0 && gamma > 0)
//         return true;
//     else
//         return false;
// }