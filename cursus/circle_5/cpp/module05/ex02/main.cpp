#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// void check_leaks()
// {
// 	system("leaks ex02");
// }

int	main(void)
{
	// ShrubberyCreationForm에 대한 exception 발생하지 않는 경우
	try {
		ShrubberyCreationForm shrubberyCreationForm("home");
		Bureaucrat bureaucrat("bureaucrat", 1);
		std::cout << shrubberyCreationForm << std::endl;
		bureaucrat.signForm(&shrubberyCreationForm);
		bureaucrat.executeForm(shrubberyCreationForm);
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (ShrubberyCreationForm::NotSignedException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (ShrubberyCreationForm::NotQualifiedException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n==========================\n" << std::endl;

	// ShrubberyCreationForm에 대한 exception 발생하는 경우
	try {
		ShrubberyCreationForm shrubberyCreationForm("home");
		Bureaucrat bureaucrat("bureaucrat", 1);
		std::cout << shrubberyCreationForm << std::endl;
		bureaucrat.signForm(&shrubberyCreationForm);
		Bureaucrat bureaucrat1("bureaucrat1", 138);
		bureaucrat1.executeForm(shrubberyCreationForm);
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (ShrubberyCreationForm::NotSignedException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (ShrubberyCreationForm::NotQualifiedException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n==========================\n" << std::endl;

	// RobotomyRequestForm 대한 exception 발생하지 않는 경우
	try {
		RobotomyRequestForm robotomyRequestForm("Jason");
		Bureaucrat bureaucrat("bureaucrat", 1);
		std::cout << robotomyRequestForm << std::endl;
		bureaucrat.signForm(&robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (ShrubberyCreationForm::NotSignedException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (ShrubberyCreationForm::NotQualifiedException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n==========================\n" << std::endl;

	// RobotomyRequestForm 대한 exception 발생하는 경우
	try {
		RobotomyRequestForm robotomyRequestForm("home");
		Bureaucrat bureaucrat("bureaucrat", 1);
		std::cout << robotomyRequestForm << std::endl;
		bureaucrat.signForm(&robotomyRequestForm);
		Bureaucrat bureaucrat1("bureaucrat1", 46);
		bureaucrat1.executeForm(robotomyRequestForm);
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (ShrubberyCreationForm::NotSignedException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (ShrubberyCreationForm::NotQualifiedException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n==========================\n" << std::endl;

	// PresidentialPardonForm에 대한 exception 발생하지 않는 경우
	try {
		PresidentialPardonForm presidentialPardonForm("Jason");
		Bureaucrat bureaucrat("bureaucrat", 1);
		std::cout << presidentialPardonForm << std::endl;
		bureaucrat.signForm(&presidentialPardonForm);
		bureaucrat.executeForm(presidentialPardonForm);
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (ShrubberyCreationForm::NotSignedException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (ShrubberyCreationForm::NotQualifiedException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n==========================\n" << std::endl;

	// PresidentialPardonForm 대한 exception 발생하는 경우
	try {
		PresidentialPardonForm presidentialPardonForm("home");
		Bureaucrat bureaucrat("bureaucrat", 1);
		std::cout << presidentialPardonForm << std::endl;
		bureaucrat.signForm(&presidentialPardonForm);
		Bureaucrat bureaucrat1("bureaucrat1", 6);
		bureaucrat1.executeForm(presidentialPardonForm);
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (ShrubberyCreationForm::NotSignedException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (ShrubberyCreationForm::NotQualifiedException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n==========================\n" << std::endl;

	// atexit(check_leaks);

	return 0;
}

