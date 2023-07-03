#include "Zombie.hpp"

int main()
{
	Zombie *one = newZombie("one");
	one->announce();
	randomChump("two");
	delete one;

	return 0;
}