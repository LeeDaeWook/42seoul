#ifndef __AFORM_HPP__
# define __AFORM_HPP__
# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class AForm {
    private:
        const std::string name;
        bool isSign;
        const unsigned int signGrade;
        const unsigned int execGrade;

    public:
        AForm();
        AForm(std::string name, unsigned int signGrade, unsigned int execGrade);
        virtual ~AForm();
        AForm(const AForm& aform);
        AForm& operator=(const AForm& aform);

        virtual const std::string getName() const;
        virtual bool getIsSign() const;
        virtual unsigned int getSignGrade() const;
        virtual unsigned int getExecGrade() const;
        
        virtual void beSigned(Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const;
        virtual void action() const = 0;

        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };

        class NotSignedException : public std::exception {
            public:
                const char *what() const throw();
        };

        class NotQualifiedException : public std::exception {
            public:
                const char *what() const throw();
        };

        class NoFormMatchedException : public std::exception {
            public:
                const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& aform);

#endif