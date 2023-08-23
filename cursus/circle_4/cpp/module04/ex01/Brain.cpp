#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default Brain constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Default Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& brain)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = brain;
}

Brain& Brain::operator=(const Brain& brain)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &brain) {
        for (int i = 0; i < 100; i++)
            (this->ideas)[i] = (brain.ideas)[i];
    }
    return *this;
}