#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type) : type(type)
{
    std::cout << "String AMateria constructor called" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "Default AMateria destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& aMateria)
{
    std::cout << "AMateria Copy constructor called" << std::endl;
    *this = aMateria;
}

AMateria& AMateria::operator=(const AMateria& aMateria)
{
    std::cout << "AMateria Copy assignment operator called" << std::endl;
    this->type = aMateria.type;
    return *this;
}

std::string const& AMateria::getType() const
{
    return type;
}