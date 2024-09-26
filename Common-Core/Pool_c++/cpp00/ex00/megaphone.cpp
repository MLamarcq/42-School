#include <iostream>

int is_digit(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

int	verif_before_print(char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (is_digit(argv[i][j]) == 1)
			{
				std::cout << "Only letters accpeted" << std::endl;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	print_message(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				argv[i][j] = argv[i][j] - 32;
			j++;
		}
		if (i != 1)
			std::cout << " ";
		std::cout << argv[i];
		i++;
	}
}

int main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEBACK NOISE *" << std::endl;
	if (argc > 1)
	{
		if (verif_before_print(argv) == 0)
			return (0);
		print_message(argv, i, j);
		std::cout << "\n";
	}
	return (0);
}
