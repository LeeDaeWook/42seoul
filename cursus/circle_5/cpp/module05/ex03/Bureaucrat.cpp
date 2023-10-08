#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("default")
{
    std::cout << "Default Bureaucrat constructor called" << std::endl;
    this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name(name)
{
    std::cout << "Bureaucrat parameter constructor called" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Default Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
    *this = bureaucrat;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
    std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
    if (this != &bureaucrat) {
        const_cast<std::string&>(this->name) = bureaucrat.name;
        this->grade = bureaucrat.grade;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    std::cout << "Bureaucrat insertion operator called" << std::endl;
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "GradeTooHighException";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException";
}

const std::string Bureaucrat::getName() const
{
    return this->name;
}

unsigned int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incGrade()
{
    if (this->getGrade() <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decGrade()
{
    if (this->getGrade() >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

void Bureaucrat::signForm(AForm &aform)
{
    if (this->getGrade() <= aform.getSignGrade() && this->getGrade() <= aform.getExecGrade()) {
        aform.beSigned(*this);
        std::cout << this->getName() << " signed " << aform.getName() << std::endl;
    }
    else if (this->getGrade() > aform.getSignGrade() && this->getGrade() <= aform.getExecGrade())
        std::cout << this->getName() << " couldn’t sign " << aform.getName() << " because bureaucrat's grade is lower than aform. grade to sign" << std::endl; 
    else if (this->getGrade() > aform.getExecGrade() && this->getGrade() <= aform.getSignGrade())
        std::cout << this->getName() << " couldn’t sign " << aform.getName() << " because bureaucrat's grade is lower than aform. grade to execute" << std::endl; 
    else
        std::cout << this->getName() << " couldn’t sign " << aform.getName() << " because bureaucrat's grade is lower than both aform's grade to execute and to sign" << std::endl;
}

void Bureaucrat::executeForm(AForm const & aform)
{
    try {
        aform.execute(*this);
        std::cout << this->getName() << " executed " << aform.getName() << std::endl;
    }
    catch (AForm::GradeTooLowException &e) {
        std::cout << this->getName() << " can't execute " << aform.getName() << " because of " << e.what() << std::endl;
    }
    catch (AForm::NotSignedException &e) {
        std::cout << this->getName() << " can't execute " << aform.getName() << " because of " << e.what() << std::endl;
    }
    catch (AForm::NotQualifiedException &e) {
        std::cout << this->getName() << " can't execute " << aform.getName() << " because of " << e.what() << std::endl;
    }
}
