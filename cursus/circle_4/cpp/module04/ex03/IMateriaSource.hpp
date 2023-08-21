#ifndef __IMATERIASOURCE_HPP__
# define __IMATERIASOURCE_HPP__
# include <iostream>
# include <string>
# include "AMateria.hpp"

class IMateriaSource {
    protected:
        AMateria* inventory[4];

    public:
        // IMateriaSource();
        // IMateriaSource(std::string const& type);
        // IMateriaSource(const IMateriaSource& iMateriaSource);
        // IMateriaSource& operator=(const IMateriaSource& iMateriaSource);
        virtual ~IMateriaSource() {};
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif