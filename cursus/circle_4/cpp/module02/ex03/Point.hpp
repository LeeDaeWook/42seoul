#pragma once
#ifndef __POINT_HPP__
# define __POINT_HPP__
# include "Fixed.hpp"

class Point {
    private:
        const Fixed x;
        const Fixed y;

    public:
        Point();
        Point(float num1, float num2);
        Point(const Point& p);
        Point& operator=(const Point& p);
        ~Point();

        Fixed getX() const;
        Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif