#pragma once
#ifndef __HUMANA_HPP__
# define  __HUMANA_HPP__

#include "Weapon.hpp"

class HumanA {

    private:
        std::string name;
        Weapon& weapon;

    public:
        HumanA(std::string name, Weapon& weapon);
        void attack();
};

#endif