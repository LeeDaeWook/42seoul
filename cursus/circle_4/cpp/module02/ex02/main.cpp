#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;

    Fixed c(20.123456789f);
    Fixed d(20.123f);
    std::cout << (a + b).toFloat() << std::endl;
    std::cout << (a - b).toFloat() << std::endl;
    std::cout << (a * b).toFloat() << std::endl;
    std::cout << (a / b).toFloat() << std::endl;
    std::cout << (c + d).toFloat() << std::endl;
    std::cout << (c - d).toFloat() << std::endl;
    std::cout << (c * d).toFloat() << std::endl;

    std::cout << " > test: " << (c > d) << std::endl;
    std::cout << " < test: " << (c < d) << std::endl;
    std::cout << " >= test: " << (c >= d) << std::endl;
    std::cout << " <= test: " << (c <= d) << std::endl;
    std::cout << " == test: " << (c == d) << std::endl;
    std::cout << " != test: " << (c != d) << std::endl;

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << a << std::endl;
    std::cout << a-- << std::endl;
    std::cout << a << std::endl;

    return 0;
}