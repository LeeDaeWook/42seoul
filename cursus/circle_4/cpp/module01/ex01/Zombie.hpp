#pragma once
#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

# include <iostream>

class Zombie {
	private:
		std::string name;

		Zombie(std::string name);

	public:
		Zombie();
		~Zombie();

		void	announce(void);
		void	setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif