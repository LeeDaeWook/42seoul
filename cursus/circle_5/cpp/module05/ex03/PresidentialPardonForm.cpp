#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "PresidentialPardonForm parameter constructor called" << std::endl;
    this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Default PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm)
{
    std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
    *this = presidentialPardonForm;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& presidentialPardonForm)
{
    std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
    if (this != &presidentialPardonForm) {
        AForm::operator=(presidentialPardonForm);
        this->target = presidentialPardonForm.getTarget();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& presidentialPardonForm)
{
    std::cout << "PresidentialPardonForm insertion operator called" << std::endl;
    os << presidentialPardonForm.getName();
    if  (presidentialPardonForm.getIsSign() == true)
        os << " is signed ";
    else if  (presidentialPardonForm.getIsSign() == false)
        os << " is not signed ";
    os << ", sign grade " << presidentialPardonForm.getSignGrade() << ", execute grade " << presidentialPardonForm.getExecGrade();
    os << ", target is " << presidentialPardonForm.getTarget();
    return os;
}

std::string PresidentialPardonForm::getTarget() const
{
    return this->target;
}

void PresidentialPardonForm::action() const
{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
