#include "Bureaucrat.hpp"

// void check_leaks()
// {
// 	system("leaks Bureaucrat");
// }

int	main(void)
{
	// exception 발생하지 않는 경우
	try {
		Bureaucrat bureaucrat = Bureaucrat("bureaucrat0", 75);
		std::cout << bureaucrat << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "==========================" << std::endl;

	// 가장 높은 grade로 Bureaucrat 생성 후 incGrade 하는 경우 
	try {
		Bureaucrat bureaucrat = Bureaucrat("bureaucrat1", 1);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "==========================" << std::endl;

	// 가장 낮은 grade로 Bureaucrat 생성 후 decGrade 하는 경우 
	try {
		Bureaucrat bureaucrat = Bureaucrat("bureaucra2", 150);
		std::cout << bureaucrat << std::endl;
		bureaucrat.decGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "==========================" << std::endl;

	// 1보다 높은 grade로 Bureaucrat 생성 하는 경우
	try {
		Bureaucrat bureaucrat = Bureaucrat("bureaucrat3", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "==========================" << std::endl;

	// 150보다 낮은 grade로 Bureaucrat 생성 하는 경우
	try {
		Bureaucrat bureaucrat = Bureaucrat("bureaucrat4", 151);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;

	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}