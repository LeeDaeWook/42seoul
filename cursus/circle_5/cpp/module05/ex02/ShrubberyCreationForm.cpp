#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm parameter constructor called" << std::endl;
    this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Default ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm)
{
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
    *this = shrubberyCreationForm;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shrubberyCreationForm)
{
    std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
    if (this != &shrubberyCreationForm) {
        AForm::operator=(shrubberyCreationForm);
        this->target = shrubberyCreationForm.getTarget();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& shrubberyCreationForm)
{
    std::cout << "ShrubberyCreationForm insertion operator called" << std::endl;
    os << shrubberyCreationForm.getName();
    if (shrubberyCreationForm.getIsSign() == true)
        os << " is signed ";
    else if (shrubberyCreationForm.getIsSign() == false)
        os << " is not signed ";
    os << ", sign grade " << shrubberyCreationForm.getSignGrade() << ", execute grade " << shrubberyCreationForm.getExecGrade();
    os << ", target is " << shrubberyCreationForm.getTarget();
    return os;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->target;
}

void ShrubberyCreationForm::action() const
{
    std::ofstream fout;
    std::string asciiTree = this->getTarget() + "_shrubbery";
    fout.open(asciiTree.c_str());
    this->writeTree(fout);
}

void ShrubberyCreationForm::writeTree(std::ofstream &fout) const
{
    fout << "Root" << std::endl;
    fout << "|-- Left child" << std::endl;
    fout << "    |-- Left grand child" << std::endl;
    fout << "|-- Right child" << std::endl;
    fout << "    |-- Right grand child" << std::endl;
}
