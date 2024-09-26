#include "ScalarConvert.class.hpp"

ScalarConvert::ScalarConvert(void)
{
	std::cout << "ScalarConvert default constructor called" << std::endl;
	return ;
}

ScalarConvert::ScalarConvert(ScalarConvert const &src)
{
	std::cout << "ScalarConvert copy constructor called" << std::endl;
	*this = src;
	return ;
}

ScalarConvert::~ScalarConvert(void)
{
	std::cout << "ScalarConvert destructor called" << std::endl;
	return ;
}

ScalarConvert & ScalarConvert::operator=(ScalarConvert const &rhs)
{
	std::cout << "ScalarConvert copy operator called" << std::endl;
	(void)rhs;
	return (*this);
}

bool ScalarConvert::is_char(std::string const str)
{
	if (str.empty())
		return (false);
	if (str.size() == 1 && std::isalpha(str[0]))
		return (true);
	return (false);
}

bool ScalarConvert::is_int(std::string const str)
{
	int i = 0;

	if (str.empty())
		return (false);
	if (str.size() > 10 && str[0] != '-')
		return (false);
	else if (str.size() > 11 && str[0] == '-')
		return (false);
	if (str[0] == '-')
		i++;
	for (; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	if ((std::strtol(str.c_str(), NULL, 10) < INT_MIN || std::strtol(str.c_str(), NULL, 10) > INT_MAX))
		return (false);
	return (true);
}

bool ScalarConvert::is_float(std::string const str)
{
	int i = 0;
	bool decimal = false;

	if (str.empty())
		return (false);
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("nanf") == 0)
		return (true);
	if (str[i] == '-')
		i++;
	if (!std::isdigit(str[i]))
		return (false);
	else
		i++;
	while (str[i])
	{
		if (!std::isdigit(str[i]) && str[i] != '.')
			break ;
		if (str[i] == '.')
		{
			decimal = true;
			i++;
		}
		else
			i++;
	}
	if (str[i] != 'f' || str[i + 1] || decimal == false)
		return (false);
	return (true);
}

bool ScalarConvert::is_double(std::string const str)
{
	int i = 0;
	bool decimal = false;

	if (str.empty())
		return (false);
	if (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("nan") == 0)
		return (true);
	if (str[i] == '-')
		i++;
	if (!std::isdigit(str[i]))
		return (false);
	else
		i++;
	while (str[i])
	{
		if (!std::isdigit(str[i]) && str[i] != '.')
			break ;
		if (str[i] == '.')
		{
			decimal = true;
			i++;
		}
		else
			i++;
	}
	if (str[i + 1] || decimal == false)
		return (false);
	return (true);
}

void	ScalarConvert::ConvertToCharAndDisplay(const char str)
{
	int	nb = static_cast <int> (str);
	float flt = static_cast <float> (str);
	double dbl = static_cast <double> (str);

	if (str == 32 || std::isgraph(str))
		std::cout << "char : '" << str << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int : " << nb << std::endl;
	std::cout << "float : " << flt << ".0f" << std::endl;
	std::cout << "double : " << dbl << ".0" << std::endl;
	return ;
}

void	ScalarConvert::ConvertToIntAndDisplay(const int nb)
{
	char str = static_cast<char>(nb);
	float flt = static_cast<float>(nb);
	double dbl = static_cast<double>(nb);

	if (str == 32 || std::isgraph(str))
		std::cout << "char : '" << str << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int : " << nb << std::endl;
	std::cout << "float : " << flt << ".0f" << std::endl;
	std::cout << "double : " << dbl << ".0" << std::endl;
	return ;
}

void	ScalarConvert::ConvertToFloatAndDisplay(float flt, std::string string)
{
	char str = static_cast <char> (flt);
	int nb = static_cast <int> (flt);
	double dbl = static_cast <double> (flt);

	if (string.compare("-inff") == 0 || string.compare("+inff") == 0 || string.compare("nanf") == 0)
	{
		HandleException(string, 1);
		return ;
	}
	if (str == 32 || std::isgraph(str))
		std::cout << "char : '" << str << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int : " << nb << std::endl;
	std::cout << "float : " << flt  << "f" << std::endl;
	std::cout << "double : " << dbl << std::endl;
}

void	ScalarConvert::ConvertToDoubleAndDisplay(double dbl, std::string string)
{
	char str = static_cast <char> (dbl);
	int nb = static_cast <int> (dbl);
	float flt = static_cast <float> (dbl);

	if (string.compare("-inf") == 0 || string.compare("+inf") == 0 || string.compare("nan") == 0)
	{
		HandleException(string, 2);
		return ;
	}
	if (str == 32 || std::isgraph(str))
		std::cout << "char : '" << str << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int : " << nb << std::endl;
	std::cout << "float : " << flt << "f" << std::endl;
	std::cout << "double : " << dbl << std::endl;
}

void	ScalarConvert::HandleException(std::string str, int nb)
{
	if (nb == 1)
	{
		int i = 0;
		
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : " << str << std::endl;
		
		if (str[0] == '+' || str[0] == '-')
			i++;
		while(str[i])
			i++;
		str.erase(i - 1, std::string::npos);
		std::cout << "double : " << str << std::endl;
	}
	if (nb == 2)
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : " << str << "f" << std::endl;
		std::cout << "double : " << str << std::endl;
	}
	return ;
}

void	ScalarConvert::DisplayAll(std::string const str)
{
	int i = 0;
	bool (*type[4])(std::string const string) = {&ScalarConvert::is_char, &ScalarConvert::is_int, &ScalarConvert::is_float, &ScalarConvert::is_double};

	char c;
	int nb;
	float flt;
	double dbl;

	while (i < 4)
	{
		if (type[i](str) == true)
			break ;
		i++;
	}
	switch (i)
	{
		case (0) :
		{
			c = str[0];
			ConvertToCharAndDisplay(c);
			break ;
		}
		case (1) :
		{
			nb = std::atoi(str.c_str());
			ConvertToIntAndDisplay(nb);
			break ;
		}
		case (2) :
		{
			flt = std::atof(str.c_str());
			ConvertToFloatAndDisplay(flt, str);
			break ;
		}
		case (3) :
		{
			dbl = std::strtod(str.c_str(), NULL);
			ConvertToDoubleAndDisplay(dbl, str);
			break ;
		}
		default :
		{
			std::cout << "char : impossible" << std::endl;
			std::cout << "int : impossible" << std::endl;
			std::cout << "float : impossible" << std::endl;
			std::cout << "double : impossible" << std::endl;
		}
	}
	return ;
}