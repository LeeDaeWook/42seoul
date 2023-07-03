#include "Zombie.hpp"

// void	check_leak()
// {
// 	system("leaks ZombieHorde");
// }

int main()
{
	Zombie *horde = zombieHorde(5, "horde");
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;

	// atexit(check_leak);
	return 0;
}