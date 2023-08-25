#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__
# include <iostream>
# include <string>

class Brain {
    private:
        std::string ideas[100];

    public:
        Brain();
        ~Brain();
        Brain(const Brain& brain);
        Brain& operator=(const Brain& brain);

        std::string getIdeas(int idx);
        void setIdeas(std::string idea, int idx);
};

#endif