#include "Point.hpp"

int main( void )
{
    Point a(5.0f, 5.0f);
    Point b(2.0f, 9.0f);
    Point c(0.0f, 5.0f);
    Point p(1.987f, 8.123f);

    std::cout << bsp(a, b, c, p) << std::endl;

    Point a1(5, 5);
    Point b1(2, 9);
    Point c1(0, 5);
    Point p1(3, 12);
    Point p2(3, 10);
    Point p3(2, 10);
    Point p4(2, 12);
    Point p5(2, 9);

    std::cout << bsp(a1, b1, c1, p1) << std::endl;
    std::cout << bsp(a1, b1, c1, p2) << std::endl;
    std::cout << bsp(a1, b1, c1, p3) << std::endl;
    std::cout << bsp(a1, b1, c1, p4) << std::endl;
    std::cout << bsp(a1, b1, c1, p5) << std::endl;

    return 0;
}