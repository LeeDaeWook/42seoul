#include "Serializer.hpp"

// void check_leaks()
// {
// 	system("leaks Serializer");
// }

int	main()
{
	Data data;
	data.data = 123;
	static Serializer serializer;

	std::cout << &data << std::endl;
	std::cout << data.data << std::endl;

	std::cout << serializer.deserialize(serializer.serialize(&data)) << std::endl;
	std::cout << serializer.deserialize(serializer.serialize(&data))->data << std::endl;

	// atexit(check_leaks);

	return 0;
}

