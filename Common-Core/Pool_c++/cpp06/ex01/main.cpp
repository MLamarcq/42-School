#include "Serializer.class.hpp"

int main()
{
	Data *ptr = new Data; //soit on alloue dynamiquement soit on verifie que non null;
	
	ptr->str = "This is a test string";
	ptr->nb = 42;
	
	//Data *ptr = NULL; //= seg fault;

	uintptr_t raw;

	try
	{
		raw = Serializer::serialize(ptr);
	}
	catch (Serializer::SerializationException &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "Can't Serialise. End of program" << std::endl;
		return (0);
	}

	Data *data;
	
	data = Serializer::deserialize(raw);
	try
	{
		Serializer::checkDeserialisation(data, ptr);
	}
	catch (Serializer::DeserialisationIntegerException &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "End of program" << std::endl;
		delete ptr;
		return (0);
	}
	catch (Serializer::DeserialisationStringException &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "End of program" << std::endl;
		delete ptr;
		return (0);
	}
	data->getvalues();
	delete ptr;
	return (0);
}


