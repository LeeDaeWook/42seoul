#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default ClapTrap constructor called" << std::endl;
    this->name = "ClapTrap";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "String ClapTrap constructor called" << std::endl;
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Default ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    this->name = claptrap.name;
    this->hitPoints = claptrap.hitPoints;
    this->energyPoints = claptrap.energyPoints;
    this->attackDamage = claptrap.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    this->name = claptrap.name;
    this->hitPoints = claptrap.hitPoints;
    this->energyPoints = claptrap.energyPoints;
    this->attackDamage = claptrap.attackDamage;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints && energyPoints) {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else
        std::cout << "ClapTrap " << name << " can't do anything!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
    if (amount > this->hitPoints)
        this->hitPoints = 0;
    else
        this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints && energyPoints) {
        std::cout << "ClapTrap " << name << " repairs itself by " << amount << " points!" << std::endl;
        this->hitPoints += amount;
        this->energyPoints--;
    }
    else
        std::cout << "ClapTrap " << name << " can't do anything!" << std::endl;
}

unsigned int ClapTrap::getHitPoints()
{
    return this->hitPoints;
}

unsigned int ClapTrap::getEnergyPoints()
{
    return this->energyPoints;
}