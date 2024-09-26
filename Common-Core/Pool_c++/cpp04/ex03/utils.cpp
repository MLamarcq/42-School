#include "AMateria.class.hpp"

int is_letter(std::string str)
{
	int j = 0;
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') \
		 || (str[i] == 32))
		{
			j++;
		}
		else
			return (0);
	}
	return (1);
}