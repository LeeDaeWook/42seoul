#include "Form.hpp"

// void check_leaks()
// {
// 	system("leaks Form");
// }

int	main(void)
{

	// exception 발생하지 않는 경우
	try {
		Form form = Form("form0", 75, 75);
		std::cout << form << std::endl;
	}
	catch (Form::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n==========================\n" << std::endl;

	// 1보다 높은 grade로 Form 생성 하는 경우
	try {
		Form form = Form("form1", 0, 0);
	}
	catch (Form::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n==========================\n" << std::endl;

	// 150보다 낮은 grade로 Form 생성 하는 경우
	try {
		Form form = Form("form2", 151, 151);
	}
	catch (Form::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n==========================\n" << std::endl;

	// beSigned() 성공 테스트
	try {
		Form form = Form("form3", 75, 75);
		Bureaucrat bureaucrat = Bureaucrat("bureaucrat0", 1);
		form.beSigned(bureaucrat);
		std::cout << form << std::endl;
	}
	catch (Form::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n==========================\n" << std::endl;

	// beSigned() 실패 테스트
	try {
		Form form = Form("form4", 75, 75);
		Bureaucrat bureaucrat = Bureaucrat("bureaucrat1", 150);
		form.beSigned(bureaucrat);
		std::cout << form << std::endl;
	}
	catch (Form::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n==========================\n" << std::endl;

	// signForm() 성공 테스트
	try {
		Form form = Form("form5", 75, 75);
		Bureaucrat bureaucrat = Bureaucrat("bureaucrat2", 1);
		bureaucrat.signForm(&form);
		std::cout << form << std::endl;
	}
	catch (Form::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n==========================\n" << std::endl;

	// signForm() 실패 테스트
	try {
		Form form = Form("form6", 75, 75);
		Bureaucrat bureaucrat = Bureaucrat("bureaucrat2", 150);
		bureaucrat.signForm(&form);
		std::cout << form << std::endl;
	}
	catch (Form::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n==========================\n" << std::endl;

	return 0;
}