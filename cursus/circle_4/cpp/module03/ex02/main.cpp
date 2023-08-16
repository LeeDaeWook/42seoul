#include "FragTrap.hpp"

int	main(void)
{
	FragTrap a("A");
	FragTrap b("B");

	a.attack("B");
	b.takeDamage(1);
	b.beRepaired(3);
    std::cout << b.getHitPoints() << std::endl;
    std::cout << b.getEnergyPoints() << std::endl;
	b.highFivesGuys();

    std::cout << "------------------------" << std::endl;

	b.attack("A");
	a.takeDamage(20);
	a.beRepaired(10);
    std::cout << a.getHitPoints() << std::endl;
    std::cout << a.getEnergyPoints() << std::endl;
	a.highFivesGuys();
    
	return (0);
}