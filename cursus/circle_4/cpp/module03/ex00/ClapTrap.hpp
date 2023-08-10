#pragma once
#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__
# include <iostream>
# include <string>

class ClapTrap {
    private:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap& claptrap);
        ClapTrap& operator=(const ClapTrap& claptrap);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        unsigned int getHitPoints();
        unsigned int getEnergyPoints();
};

#endif