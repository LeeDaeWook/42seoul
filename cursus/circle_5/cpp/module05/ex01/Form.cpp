#include "Form.hpp"

Form::Form() : name("default"), isSign(false), signGrade(150), execGrade(150)
{
    std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string name, unsigned int signGrade, unsigned int execGrade) : name(name), isSign(false), signGrade(signGrade), execGrade(execGrade)
{
    std::cout << "Form parameter constructor called" << std::endl;
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::~Form()
{
    std::cout << "Default Form destructor called" << std::endl;
}

Form::Form(const Form& form) : name(form.getName()), isSign(form.getIsSign()), signGrade(form.getSignGrade()), execGrade(form.getExecGrade())
{
    std::cout << "Form Copy constructor called" << std::endl;
    *this = form;
}

Form& Form::operator=(const Form& form)
{
    std::cout << "Form Copy assignment operator called" << std::endl;
    if (this != &form) {
        const_cast<std::string&>(this->name) = form.name;
        this->isSign = form.isSign;
        const_cast<unsigned int&>(this->signGrade) = form.signGrade;
        const_cast<unsigned int&>(this->execGrade) = form.execGrade;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    std::cout << "Form insertion operator called" << std::endl;
    os << form.getName();
    if (form.getIsSign() == true)
        os << " is signed ";
    else if (form.getIsSign() == false)
        os << " is not signed ";
    os << ", sign grade " << form.getSignGrade() << ", execute grade " << form.getExecGrade();
    return os;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "GradeTooHighException";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException";
}

const std::string Form::getName() const
{
    return this->name;
}

bool Form::getIsSign() const
{
    return this->isSign;
}

unsigned int Form::getSignGrade() const
{
    return this->signGrade;
}

unsigned int Form::getExecGrade() const
{
    return this->execGrade;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getSignGrade())
        this->isSign = true;
    else if (this->getSignGrade() > 150)
        throw GradeTooLowException();
}
