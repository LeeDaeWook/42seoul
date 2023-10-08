# include "Intern.hpp"

// void check_leaks()
// {
// 	system("leaks Intern");
// }

int	main(void)
{
	// intern에 대한 exception 발생하지 않는 경우 - robotomy request form
	try {
		Intern intern;
		AForm *form = intern.makeForm("robotomy request", "James");
		std::cout << *form << std::endl;

		Bureaucrat bureaucrat("bureaucrat", 1);
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		if (form)
			free(form);
	}
	catch (AForm::NoFormMatchedException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n==========================\n" << std::endl;

	// intern에 대한 exception 발생하지 않는 경우 - shrubbery creation form
	try {
		Intern intern;
		AForm *form = intern.makeForm("shrubbery creation", "home");
		std::cout << *form << std::endl;

		Bureaucrat bureaucrat("bureaucrat", 1);
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		if (form)
			free(form);
	}
	catch (AForm::NoFormMatchedException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n==========================\n" << std::endl;

	// intern에 대한 exception 발생하는 경우 - 존재하지 않는 form
	Intern intern;
	AForm *form = intern.makeForm("exception request", "home");
	if (form) {
		std::cout << *form << std::endl;
		free(form);
	}

	// atexit(check_leaks);

	return 0;
}

