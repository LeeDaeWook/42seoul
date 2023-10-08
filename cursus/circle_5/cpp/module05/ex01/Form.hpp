#ifndef __FORM_HPP__
# define __FORM_HPP__
# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Form {
    private:
        const std::string name;
        bool isSign;
        const unsigned int signGrade;
        const unsigned int execGrade;

    public:
        Form();
        Form(std::string name, unsigned int signGrade, unsigned int execGrade);
        virtual ~Form();
        Form(const Form& form);
        Form& operator=(const Form& form);

        virtual const std::string getName() const;
        virtual bool getIsSign() const;
        virtual unsigned int getSignGrade() const;
        virtual unsigned int getExecGrade() const;
        virtual void beSigned(Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif