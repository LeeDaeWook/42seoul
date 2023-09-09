#ifndef __CURE_HPP__
# define __CURE_HPP__
# include "AMateria.hpp"

class Cure : public AMateria {
    public:
        Cure();
        Cure(std::string const& type);
        virtual ~Cure();
        Cure(const Cure& cure);
        Cure& operator=(const Cure& cure);

        Cure* clone() const;
        void use(ICharacter& target);
};

#endif