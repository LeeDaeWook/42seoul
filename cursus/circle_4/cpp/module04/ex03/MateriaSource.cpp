#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "Default MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    std::cout << "Default MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i])
            delete this->inventory[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
    std::cout << "MateriaSource Copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    *this = materiaSource;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiaSource)
{
    std::cout << "MateriaSource Copy assignment operator called" << std::endl;
    (void)materiaSource;
    return *this;
}

void MateriaSource::learnMateria(AMateria* aMateria)
{
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] == NULL) {
            this->inventory[i] = aMateria;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] && this->inventory[i]->getType() == type) {
            return this->inventory[i]->clone();
        }
    }
    return NULL;
}

