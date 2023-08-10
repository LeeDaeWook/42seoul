#pragma once
#ifndef __FIXED_HPP__
# define __FIXED_HPP__
#include <iostream>
#include <string>

class Fixed {
    private:
        int value;
        static const int fracBits;

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &fixed);
        Fixed& operator=(const Fixed& fixed);

        int getRawBits() const;
        void setRawBits(int const raw);

};

#endif