#ifndef SCARLARCONVERT_CLASS_HPP
#define SCARLARCONVERT_CLASS_HPP


#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cerrno>

class ScalarConvert
{
	public : 

			ScalarConvert &operator=(ScalarConvert const &rhs);

			static bool is_char(std::string const str);
			static bool is_int(std::string const str);
			static bool is_float(std::string const str);
			static bool is_double(std::string const str);

			static void	ConvertToCharAndDisplay(const char str);
			static void	ConvertToIntAndDisplay(const int nb);
			static void	ConvertToFloatAndDisplay(float flt, std::string);
			static void	ConvertToDoubleAndDisplay(double dbl, std::string);
			static void	HandleException(std::string str, int nb);
			static void	DisplayAll(std::string const str);

	private :

			ScalarConvert(void);
			ScalarConvert(ScalarConvert const &src);
			~ScalarConvert(void);
};

#endif