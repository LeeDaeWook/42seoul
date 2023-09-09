#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Default Animal constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Default Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& animal)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = animal;
}

Animal& Animal::operator=(const Animal& animal)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &animal)
        this->type = animal.type;
    return *this;
}

std::string Animal::getType() const
{
    return this->type;
}