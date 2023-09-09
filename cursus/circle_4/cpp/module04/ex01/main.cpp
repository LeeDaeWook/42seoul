#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// void check_leaks()
// {
// 	system("leaks Brain");
// }

int	main(void)
{
	Animal* animal[10];
	for (int i = 0; i < 10; i++) {
		if (i < 5)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}

	for (int i = 0; i < 10; i++) {
		animal[i]->makeSound();
	}
	
	for (int i = 0; i < 10; i++) {
		delete animal[i];
	}

	Cat cat1;
	cat1.getBrain()->setIdeas("aaa", 0);
	cat1.getBrain()->setIdeas("bbb", 1);

	std::cout << cat1.getBrain()->getIdeas(0) << std::endl; 
	std::cout << cat1.getBrain()->getIdeas(1) << std::endl; 

	// atexit(check_leaks);

	return 0;
}