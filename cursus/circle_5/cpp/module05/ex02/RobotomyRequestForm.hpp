#ifndef __ROBOTOMYREQUESTFORM_HPP__
# define __ROBOTOMYREQUESTFORM_HPP__

# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& robotomyRequestForm);

        std::string getTarget() const;
        void action() const;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& RobotomyRequestForm);

#endif