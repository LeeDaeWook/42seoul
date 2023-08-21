#include "Ice.hpp"

Ice::Ice()
{
    std::cout << "Default Ice constructor called" << std::endl;
    this->type = "ice";
}

Ice::~Ice()
{
    std::cout << "Default Ice destructor called" << std::endl;   
}

Ice::Ice(const Ice& ice)
{
    std::cout << "Ice Copy constructor called" << std::endl;
    *this = ice;
}

Ice& Ice::operator=(const Ice& ice)
{
    std::cout << "Ice Copy assignment operator called" << std::endl;
    (void)ice;
    return *this;
}

Ice* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.name << " *" << std::endl; 
}

