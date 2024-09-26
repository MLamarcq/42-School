#ifndef SERIALIZER_CLASS_HPP
#define SERIALIZER_CLASS_HPP

#include <string>
#include <iostream>
//#include <cstdint>
#include <stdint.h>

struct Data
{
	int			nb;
	std::string	str;
	void		getvalues(void) const;
	int			temp;
	std::		string tmp;
};


class Serializer
{
	public :
				Serializer &operator=(Serializer const &rhs);

				static Data *deserialize(uintptr_t raw);
				static uintptr_t serialize(Data *ptr);
				static void checkDeserialisation(Data *data, Data *ptr);


				class SerializationException : public std::exception
				{
					public :
							const char *what() const throw();
				};
				
				class DeserialisationIntegerException : public std::exception
				{
					public :
							const char *what() const throw();
				};
				
				class DeserialisationStringException : public std::exception
				{
					public :
							const char *what() const throw();
				};
	private :

			Serializer(void);
			Serializer(Serializer const &src);
			~Serializer(void);
};


#endif