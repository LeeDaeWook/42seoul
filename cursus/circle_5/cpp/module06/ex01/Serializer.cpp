#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Default Serializer constructor called" << std::endl;
}

Serializer::~Serializer()
{
    std::cout << "Default Serializer destructor called" << std::endl;
}

Serializer::Serializer(const Serializer& serializer)
{
    std::cout << "Serializer Copy constructor called" << std::endl;
    *this = serializer;
}

Serializer& Serializer::operator=(const Serializer& serializer)
{
    std::cout << "Serializer Copy assignment operator called" << std::endl;
    (void)serializer;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
