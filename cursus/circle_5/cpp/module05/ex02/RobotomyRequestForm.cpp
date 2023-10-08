#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << "RobotomyRequestForm parameter constructor called" << std::endl;
    this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Default RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm)
{
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
    *this = robotomyRequestForm;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& robotomyRequestForm)
{
    std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
    if (this != &robotomyRequestForm) {
        AForm::operator=(robotomyRequestForm);
        this->target = robotomyRequestForm.getTarget();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& robotomyRequestForm)
{
    std::cout << "RobotomyRequestForm insertion operator called" << std::endl;
    os << robotomyRequestForm.getName();
    if (robotomyRequestForm.getIsSign() == true)
        os << " is signed ";
    else if (robotomyRequestForm.getIsSign() == false)
        os << " is not signed ";
    os << ", sign grade " << robotomyRequestForm.getSignGrade() << ", execute grade " << robotomyRequestForm.getExecGrade();
    os << ", target is " << robotomyRequestForm.getTarget();
    return os;
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->target;
}

void RobotomyRequestForm::action() const
{
    std::cout << "Drilling sound..." << std::endl;
    if (std::time(NULL) % 2 == 1)
        std::cout << this->getTarget() << " has been robotomized successfully 50\% of the time" << std::endl;
    else if (std::time(NULL) % 2 == 0)
        std::cout << "The robotomy failed" << std::endl;
}
