#include "Serializer.class.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer default constructor called" << std::endl;
	return ;
}

Serializer::Serializer(Serializer const &src)
{
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = src;
	return ;
}
Serializer & Serializer::operator=(Serializer const &rhs)
{
	std::cout << "Serializer copy operator called" << std::endl;
	(void)rhs;
	return (*this);
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer destructor called" << std::endl;
	return ;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	if (ptr == NULL)
	{
		throw (SerializationException());
		return (0);
	}
	ptr->temp = ptr->nb;
	ptr->tmp = ptr->str;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data * Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

void Serializer::checkDeserialisation(Data *data, Data *ptr)
{
	if (data->nb != ptr->temp)
	{
		throw (DeserialisationIntegerException());
	}
	if (data->str != ptr->tmp)
	{
		throw (DeserialisationStringException());
	}
	return ;
}

const char *Serializer::SerializationException::what() const throw ()
{
	return ("Data pointer in NULL, can't serialize");
}

const char *Serializer::DeserialisationIntegerException::what() const throw()
{
	return ("Integer is not the same than before the serialisation. Deserialisation failed");
}

const char *Serializer::DeserialisationStringException::what() const throw()
{
	return ("String is not the same than before the serialisation. Deserialisation failed");
}