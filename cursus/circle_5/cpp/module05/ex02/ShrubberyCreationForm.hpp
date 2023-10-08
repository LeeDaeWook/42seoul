#ifndef __SHRUBBERYCREATIONFORM_HPP__
# define __SHRUBBERYCREATIONFORM_HPP__

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    private:
        std::string target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& shrubberyCreationForm);

        std::string getTarget() const;
        void action() const;
        void writeTree(std::ofstream &fout) const;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& shrubberyCreationForm);

#endif