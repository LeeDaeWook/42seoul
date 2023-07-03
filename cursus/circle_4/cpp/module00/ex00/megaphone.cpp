#include <iostream>

int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
	else
	{
		argv++;
		while (*argv)
		{
			i = 0;
			while ((*argv)[i])
			{
				std::cout << static_cast<char>(std::toupper((*argv)[i])); // toupper's return value is int
				i++;
			}
			argv++;
		}
		std::cout << std::endl;
	}
	return (0);
}