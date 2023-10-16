#include "Serializer.hpp"

// void check_leaks()
// {
// 	system("leaks Serializer");
// }

int	main()
{
	Data data;
	data.data = 123;

	std::cout << &data << std::endl;
	std::cout << data.data << std::endl;

	std::cout << Serializer::deserialize(Serializer::serialize(&data)) << std::endl;
	std::cout << Serializer::deserialize(Serializer::serialize(&data))->data << std::endl;

	// atexit(check_leaks);

	return 0;
}

