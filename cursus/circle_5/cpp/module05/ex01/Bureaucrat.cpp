#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void Bureaucrat::signForm(Form &form)
{
    if (this->getGrade() <= form.getSignGrade()) {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    else
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because bureaucrat's grade is lower than form's grade to sign" << std::endl;
}
