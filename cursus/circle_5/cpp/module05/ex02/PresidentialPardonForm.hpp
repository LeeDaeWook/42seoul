#ifndef __PRESIDENTIALPARDONFORM_HPP__
# define __PRESIDENTIALPARDONFORM_HPP__

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& presidentialPardonForm);

        std::string getTarget() const;
        void action() const;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& PresidentialPardonForm);

#endif