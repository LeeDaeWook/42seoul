#include "Cure.hpp"

Cure::Cure()
{
    std::cout << "Default Cure constructor called" << std::endl;
    this->type = "cure";
}

Cure::~Cure()
{
    std::cout << "Default Cure destructor called" << std::endl;   
}

Cure::Cure(const Cure& cure)
{
    std::cout << "Cure Copy constructor called" << std::endl;
    *this = cure;
}

Cure& Cure::operator=(const Cure& cure)
{
    std::cout << "Cure Copy assignment operator called" << std::endl;
    (void)cure;
    return *this;
}

Cure* Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.name << "’s wounds *" << std::endl; 
}

