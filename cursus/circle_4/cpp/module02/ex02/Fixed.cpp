#include "Fixed.hpp"

const int Fixed::fracBits = 8;

Fixed::Fixed()
{
    value = 0;
}

Fixed::Fixed(const int i)
{
    value = i << fracBits;
}

Fixed::Fixed(const float f)
{
    value = roundf(f * (1 << fracBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

float Fixed::toFloat() const
{
    return static_cast<float>(value) / (1 << fracBits);
}

int Fixed::toInt() const
{
    return value >> fracBits;
}

Fixed::~Fixed()
{

}

Fixed::Fixed(const Fixed &fixed)
{
    value = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    if (this != &fixed)
        this->setRawBits(fixed.getRawBits());
    return *this;
}

int Fixed::getRawBits() const
{
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

Fixed Fixed::operator+(const Fixed& fixed)
{
    Fixed ret;
    ret.setRawBits(this->getRawBits() + fixed.getRawBits());
    return ret;
}

Fixed Fixed::operator-(const Fixed& fixed)
{
    Fixed ret;
    ret.setRawBits(this->getRawBits() - fixed.getRawBits());
    return ret;
}

Fixed Fixed::operator*(const Fixed& fixed)
{
    Fixed ret;
    ret.setRawBits((this->getRawBits() * fixed.getRawBits()) >> this->fracBits);
    return ret;
}

Fixed Fixed::operator/(const Fixed& fixed)
{
    Fixed ret;
    ret.setRawBits((this->getRawBits() / fixed.getRawBits()) << this->fracBits);
    return ret;
}

bool Fixed::operator>(const Fixed& fixed)
{
    return this->getRawBits() > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed& fixed)
{
    return this->getRawBits() < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed& fixed)
{
    return this->getRawBits() >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed& fixed)
{
    return this->getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed& fixed)
{
    return this->getRawBits() == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed& fixed)
{
    return this->getRawBits() != fixed.getRawBits();
}

Fixed& Fixed::operator++()
{
    ++value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(this->toFloat());
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--()
{
    --value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(this->toFloat());
    --(*this);
    return temp;
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
    return num1.getRawBits() < num2.getRawBits() ? num1 : num2;
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
    return num1.getRawBits() < num2.getRawBits() ? num1 : num2;
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
    return num1.getRawBits() > num2.getRawBits() ? num1 : num2;
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
    return num1.getRawBits() > num2.getRawBits() ? num1 : num2;
}