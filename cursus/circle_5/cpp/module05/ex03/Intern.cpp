#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Default Intern constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Default Intern destructor called" << std::endl;
}

Intern::Intern(const Intern& intern)
{
    std::cout << "Intern Copy constructor called" << std::endl;
    *this = intern;
}

Intern& Intern::operator=(const Intern& intern)
{
    std::cout << "Intern Copy assignment operator called" << std::endl;
    (void)intern;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Intern& intern)
{
    std::cout << "Intern insertion operator called" << std::endl;
    (void)intern;
    return os;
}
 
AForm *Intern::makeForm(std::string formName, std::string target)
{
    AForm* (Intern::*fp)(std::string target);
    try {
        fp = !formName.compare("shrubbery creation") ? \
            &Intern::makeShrubbery : !formName.compare("robotomy request") ? \
            &Intern::makeRobotomy : !formName.compare("presidential pardon") ? \
            &Intern::makePresidential : throw AForm::NoFormMatchedException();
    }
    catch (AForm::NoFormMatchedException &e) {
        std::cout << e.what() << std::endl;
        return NULL;
    }
    std::cout << "Intern creates " << formName << std::endl;
    return (this->*fp)(target);
}

AForm *Intern::makeShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}
