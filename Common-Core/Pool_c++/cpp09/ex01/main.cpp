#include "RPN.hpp"

int	check_allowed_char(char *argv)
{
	int i = 0;
	if (!argv)
		return (0);
	while (argv[i])
	{
		if ((argv[i] >= '0' && argv[i] <= '9') || argv[i] == ' ' || \
			argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/')
			i++;
		else
		{
			std::cout << "Wrong format in argument. Only digit and '+ - * /' are allowed" << std::endl;
			return (0);
		}
	}
	return (1);
}

int	check_numbers(char *argv)
{
	int i = 0;
	int count = 0;
	int sign = 0;
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
		{
			if (argv[i + 1] != ' ' && argv[i + 1] != '\0')
			{
				std::cout << "Error : Wrong argument format" << std::endl;
				return (0);
			}
			i++;
			count++;
		}
		else
		{
			if (argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/')
			{
				if (argv[i + 1] != ' ' && argv[i + 1] != '\0')
				{
					std::cout << "Error : Wrong argument format" << std::endl;
					return (0);
				}
				sign++;
			}
			i++;
		}
	}
	if (count >= sign + 2)
	{
		std::cout << "Error : Wrong argument format" << std::endl;
		return (0);
	}
	if (count == 0)
	{
		std::cout << "Error : You need numbers in argument" << std::endl;
		return (0);
	}
	if (sign >= count)
	{
		std::cout << "Error : Too much sign in argument. Numbers of sign must be less than numbers" << std::endl;
		return (0);
	}
	if (sign == 0)
	{
		std::cout << "Error : You need sign in you argument" << std::endl;
		return (0);
	}
	if (count - sign > 1)
	{
		std::cout << "Error : Too few sign in your operation. Number of sign has to be one less than numbers" << std::endl;
		return (0);
	}
	return (1);
}

int	parsing(char *argv)
{
	if (check_allowed_char(argv) == 0)
		return (0);
	if (check_numbers(argv) == 0)
		return (0);
	return (1);
}


int main(int argc, char **argv)
{
	if (parsing(argv[1]) == 0)
		return (0);
	std::string base(argv[1]);
	RPN rpn(base);
	rpn.do_polish_notation();
	(void)argc;
	return (0);
}