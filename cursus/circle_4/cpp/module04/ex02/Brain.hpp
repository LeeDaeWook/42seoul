#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__
# include <iostream>
# include <string>

class Brain {
    private:

    public:
        Brain();
        ~Brain();
        Brain(const Brain& brain);
        Brain& operator=(const Brain& brain);

        std::string ideas[100];

};

#endif