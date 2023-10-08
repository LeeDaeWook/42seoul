#include "AForm.hpp"

AForm::AForm() : name("default"), isSign(false), signGrade(150), execGrade(150)
{
    std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(std::string name, unsigned int signGrade, unsigned int execGrade) : name(name), isSign(false), signGrade(signGrade), execGrade(execGrade)
{
    std::cout << "AForm parameter constructor called" << std::endl;
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::~AForm()
{
    std::cout << "Default AForm destructor called" << std::endl;
}

AForm::AForm(const AForm& aform) : name(aform.getName()), isSign(aform.getIsSign()), signGrade(aform.getSignGrade()), execGrade(aform.getExecGrade())
{
    std::cout << "AForm Copy constructor called" << std::endl;
    *this = aform;
}

AForm& AForm::operator=(const AForm& aform)
{
    std::cout << "AForm Copy assignment operator called" << std::endl;
    if (this != &aform) {
        const_cast<std::string&>(this->name) = aform.name;
        this->isSign = aform.isSign;
        const_cast<unsigned int&>(this->signGrade) = aform.signGrade;
        const_cast<unsigned int&>(this->execGrade) = aform.execGrade;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& aform)
{
    std::cout << "AForm insertion operator called" << std::endl;
    os << aform.getName();
    if (aform.getIsSign() == true)
        os << " is signed ";
    else if (aform.getIsSign() == false)
        os << " is not signed ";
    os << ", sign grade " << aform.getSignGrade() << ", execute grade " << aform.getExecGrade();
    return os;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "GradeTooHighException";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException";
}

const char *AForm::NotSignedException::what() const throw()
{
    return "NotSignedException";
}

const char *AForm::NotQualifiedException::what() const throw()
{
    return "NotQualifiedException";
}

const std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSign() const
{
    return this->isSign;
}

unsigned int AForm::getSignGrade() const
{
    return this->signGrade;
}

unsigned int AForm::getExecGrade() const
{
    return this->execGrade;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getSignGrade())
        this->isSign = true;
    else if (this->getSignGrade() > 150)
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (this->getIsSign() && executor.getGrade() <= this->getExecGrade())
        this->action();
    else if (this->getIsSign() && executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    else if (!this->getIsSign() && executor.getGrade() <= this->getExecGrade())
        throw NotSignedException();
    else
        throw NotQualifiedException();
}