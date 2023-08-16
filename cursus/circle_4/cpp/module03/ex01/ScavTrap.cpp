#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Default ScavTrap constructor called" << std::endl;
    this->name = "ScavTrap";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "String ScavTrap constructor called" << std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Default ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap)
{
    std::cout << "Copy ScavTrap constructor called" << std::endl;
    this->name = scavTrap.name;
    this->hitPoints = scavTrap.hitPoints;
    this->energyPoints = scavTrap.energyPoints;
    this->attackDamage = scavTrap.attackDamage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
    std::cout << "Copy ScavTrap assignment operator called" << std::endl;
    this->name = scavTrap.name;
    this->hitPoints = scavTrap.hitPoints;
    this->energyPoints = scavTrap.energyPoints;
    this->attackDamage = scavTrap.attackDamage;
    return *this;
}

void ScavTrap::guardGate()
{
    if (this->hitPoints)
        std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
    else
        std::cout << "ScavTrap " << this->name << " can't do anything!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->hitPoints && this->energyPoints) {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else
        std::cout << "ScavTrap " << name << " can't do anything!" << std::endl;
}