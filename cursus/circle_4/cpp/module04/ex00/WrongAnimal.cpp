#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Default WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    *this = wrongAnimal;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    if (this != &wrongAnimal)
        this->type = wrongAnimal.type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}