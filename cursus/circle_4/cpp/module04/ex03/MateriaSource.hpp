#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& materiaSource);
        MateriaSource& operator=(const MateriaSource& materiaSource);
        ~MateriaSource();

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif