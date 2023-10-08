#ifndef __INTERN_HPP__
# define __INTERN_HPP__

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
    public:
        Intern();
        ~Intern();
        Intern(const Intern& intern);
        Intern& operator=(const Intern& intern);

        AForm* makeForm(std::string name, std::string target);
        AForm* makeShrubbery(std::string target);
        AForm* makeRobotomy(std::string target);
        AForm* makePresidential(std::string target);
};

std::ostream& operator<<(std::ostream& os, const Intern& intern);

#endif