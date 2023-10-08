#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__
# include <iostream>
# include <string>
# include <exception>

class AForm;

class Bureaucrat {
    private:
        const std::string name;
        unsigned int grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, unsigned int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& bureaucrat);
        Bureaucrat& operator=(const Bureaucrat& bureaucrat);

        const std::string getName() const;
        unsigned int getGrade() const;
        
        void incGrade();
        void decGrade();
        void signForm(AForm &aform);
        void executeForm(AForm const & aform);

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