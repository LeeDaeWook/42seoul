#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Default Dog constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "Default Dog destructor called" << std::endl;
    delete this->brain;
}

Dog::Dog(const Dog& dog)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = dog;
}

Dog& Dog::operator=(const Dog& dog)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    this->type = dog.type;
    if (this->brain != NULL)
        delete this->brain;
    this->brain = new Brain(*dog.brain);
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "woof woof!" << std::endl;
}