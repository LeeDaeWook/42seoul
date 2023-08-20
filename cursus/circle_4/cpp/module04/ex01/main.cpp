#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void check_leaks()
{
	system("leaks Brain");
}

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

	Dog dog1;
	for (int i = 0; i < 100; i++) {
		dog1.brain->ideas[i] = "a";
	}
	
	Dog dog2(dog1);
	for (int i = 0; i < 100; i++) {
		std::cout << dog2.brain->ideas[i] << " ";
	}

	Dog dog3;
	Dog dog4;

	dog3 = dog4;

	atexit(check_leaks);

	return 0;
}