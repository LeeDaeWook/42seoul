#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__
# include <iostream>
# include <string>
# include <exception>

class Bureaucrat {
    private:
        const std::string name;
        unsigned int grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, unsigned int grade);
        virtual ~Bureaucrat();
        Bureaucrat(const Bureaucrat& bureaucrat);
        Bureaucrat& operator=(const Bureaucrat& bureaucrat);

        virtual const std::string getName() const;
        virtual unsigned int getGrade() const;
        virtual void incGrade();
        virtual void decGrade();

        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif