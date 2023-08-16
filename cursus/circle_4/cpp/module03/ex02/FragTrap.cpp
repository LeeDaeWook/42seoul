#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Default FragTrap constructor called" << std::endl;
    this->name = "FragTrap";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "String FragTrap constructor called" << std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "Default FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    this->name = fragTrap.name;
    this->hitPoints = fragTrap.hitPoints;
    this->energyPoints = fragTrap.energyPoints;
    this->attackDamage = fragTrap.attackDamage;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    this->name = fragTrap.name;
    this->hitPoints = fragTrap.hitPoints;
    this->energyPoints = fragTrap.energyPoints;
    this->attackDamage = fragTrap.attackDamage;
    return *this;
}

void FragTrap::highFivesGuys()
{
    if (this->hitPoints)
        std::cout << "High fives!" << std::endl;
    else
        std::cout << "FragTrap " << name << " can't do anything!" << std::endl;
}