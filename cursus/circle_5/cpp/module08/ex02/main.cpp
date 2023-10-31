#include "MutantStack.hpp"

// void check_leaks()
// {
// 	system("leaks MutantStack");
// }

#include <stack>
#include <list>

int	main()
{
	std::stack<int> s;
	s.push(5);
	s.push(17);

	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	MutantStack<int>::iterator it = mstack.begin();

	// Iterator<int> it;

	MutantStack<int> mstack2(mstack);

	for (int i = 0; i < 3; i++)
	{
		std::cout << "mstack : " << mstack.top() << std::endl;
		mstack.pop();
	}

	std::cout << "====================" << std::endl;

	for (int i = 0; i < 3; i++)
	{
		std::cout << "mstack2 : " <<  mstack2.top() << std::endl;
		mstack2.pop();
	}



	// std::list<int> l;
	// l.push_back(5);
	// l.push_back(1);
	// l.push_back(2);
	// l.push_back(3);
	// l.push_back(4);
	// l.push_back(17);

	// std::list<int>::iterator it = l.begin();
	// std::list<int>::iterator ite = l.end();

	// for (; it != ite; it++) {
	// 	// std::cout << *it << std::endl;
	// 	// std::list<int>::iterator tmp = it++;
	// 	// *it = 42;
	// 	std::cout << *it << std::endl;
	// 	std::cout << l.front() << std::endl;
	// 	l.pop_front();
	// }



	// MutantStack<int> mstack;

	// mstack.push(5);
	// mstack.push(17);

	// std::cout << mstack.top() << std::endl;

	// mstack.pop();

	// std::cout << mstack.size() << std::endl;

	// mstack.push(3);
	// mstack.push(5);
	// mstack.push(737);
	// mstack.push(0);

	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();

	// ++it;
	// --it;

	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }

	// std::stack<int> s(mstack);

	// atexit(check_leaks);

	return 0;
}

