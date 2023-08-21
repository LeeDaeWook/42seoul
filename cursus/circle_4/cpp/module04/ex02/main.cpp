#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// void check_leaks()
// {
// 	system("leaks Abstract");
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

	// atexit(check_leaks);

	return 0;
}