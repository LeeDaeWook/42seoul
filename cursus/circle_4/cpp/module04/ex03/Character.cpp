#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
    std::cout << "Default Character constructor called" << std::endl;
    this->addressDB = NULL;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(std::string const& name)
{
    std::cout << "String Character constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    this->name = name;
}

Character::~Character()
{
    std::cout << "Default Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i])
            delete this->inventory[i];
    }
    delete this->addressDB;
}

Character::Character(const Character& character)
{
    std::cout << "Character Copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    *this = character;
}

Character& Character::operator=(const Character& character)
{
    std::cout << "Character Copy assignment operator called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] != NULL)
            delete this->inventory[i];
        this->inventory[i] = character.inventory[i]; 
    }
    this->name = character.name;
    return *this;
}

std::string const& Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] == NULL) {
            this->inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3) {
        this->addressDB = this->inventory[idx];
        this->inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    (this->inventory[idx])->use(target);
}
