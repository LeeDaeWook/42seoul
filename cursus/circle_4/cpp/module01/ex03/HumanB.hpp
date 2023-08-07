#pragma once
#ifndef __HUMANB_HPP__
# define  __HUMANB_HPP__

#include "Weapon.hpp"

class HumanB {

    private:
        Weapon* weapon;
        std::string name;

    public:
        HumanB(std::string name);
        void attack();
        void setWeapon(Weapon& weapon);
};

#endif