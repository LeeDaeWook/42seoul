#include "iter.hpp"

// void check_leaks()
// {
// 	system("leaks iter");
// }

// int	main()
// {
// 	const int arr_i[5] = {1, 2, 3, 4, 5};

// 	iter(arr_i, 5, printElement);

// 	std::cout << "==============" << std::endl;

// 	const int arr_ci[5] = {1, 2, 3, 4, 5};

// 	iter(arr_ci, 5, printElement);

// 	std::cout << "==============" << std::endl;

// 	double arr_d[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

// 	iter(arr_d, 5, printElement);

// 	std::cout << "==============" << std::endl;

// 	const double arr_cd[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

// 	iter(arr_cd, 5, printElement);

// 	std::cout << "==============" << std::endl;

// 	atexit(check_leaks);

// 	return 0;
// }

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}
