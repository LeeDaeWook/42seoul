#pragma once
#ifndef __FIXED_HPP__
# define __FIXED_HPP__
# include <iostream>
# include <string>
# include <cmath>

class Fixed {
    private:
        int value;
        static const int fracBits;

    public:
        Fixed();
        Fixed(const int i);
        Fixed(const float f);
        ~Fixed();
        Fixed(const Fixed &fixed);
        Fixed& operator=(const Fixed& fixed);

        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat() const;
        int toInt() const;

        Fixed operator+(const Fixed& fixed);
        Fixed operator-(const Fixed& fixed);
        Fixed operator*(const Fixed& fixed);
        Fixed operator/(const Fixed& fixed);

        bool operator>(const Fixed& fixed);
        bool operator<(const Fixed& fixed);
        bool operator>=(const Fixed& fixed);
        bool operator<=(const Fixed& fixed);
        bool operator==(const Fixed& fixed);
        bool operator!=(const Fixed& fixed);

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        static Fixed& min(Fixed& num1, Fixed& num2);
        static const Fixed& min(const Fixed& num1, const Fixed& num2);
        static Fixed& max(Fixed& num1, Fixed& num2);
        static const Fixed& max(const Fixed& num1, const Fixed& num2);

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif