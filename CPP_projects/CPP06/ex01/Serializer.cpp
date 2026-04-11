#include "Serializer.hpp"

Serializer::Serializer()
{
    // std::cout << "Serializer Default Constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
    (void)other;
    // std::cout << "Serializer Copy Constructor called" << std::endl;
}

Serializer::~Serializer()
{
    std::cout << "Serializer Destructor called" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    (void)other;
    // std::cout << "Serializer Copy assignment operator called" << std::endl;
    return (*this);
}

unsigned long Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<unsigned long>(ptr);
}


Data* Serializer::deserialize(unsigned long raw)
{
    return reinterpret_cast<Data*>(raw);
}