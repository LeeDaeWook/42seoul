#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("A");
	ScavTrap b("B");

	a.attack("B");
	b.takeDamage(1);
	b.beRepaired(3);
    std::cout << b.getHitPoints() << std::endl;
    std::cout << b.getEnergyPoints() << std::endl;
	b.guardGate();

    std::cout << "------------------------" << std::endl;

	b.attack("A");
	a.takeDamage(20);
	a.beRepaired(10);
    std::cout << a.getHitPoints() << std::endl;
    std::cout << a.getEnergyPoints() << std::endl;
	a.guardGate();

	return (0);
}