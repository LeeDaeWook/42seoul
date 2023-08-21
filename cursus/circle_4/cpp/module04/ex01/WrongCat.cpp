#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "Default WrongCat constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "Default WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = wrongCat;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat)
{
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    this->type = wrongCat.type;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "woof woof!" << std::endl;
}