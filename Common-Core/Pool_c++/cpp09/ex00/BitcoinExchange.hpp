#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <fstream>

class Bitcoin
{
	public :

			Bitcoin(void);
			Bitcoin(Bitcoin const & src);
			~Bitcoin(void);

			Bitcoin & operator=(Bitcoin const &rhs);

			std::map<std::string, double>	getMap(void) const;
			void							open_and_save_input(std::string str);
			void							parse_tab_date(std::string tab);
			void							parse_pipe_tab(std::string tab);
			int								is_digit(char c);
			void							check_number(std::string tab);
			void							do_operation(std::string tab);
			void							do_program(void);


			class ErrorOpeningFileException : public std::exception
			{
				public :
						const char *what() const throw();
			};

			class WrongFileFormatException : public std::exception
			{
				public :
						const char *what() const throw();
			};


			class WrongDateFormatException : public std::exception
			{
				public :
						const char *what() const throw();
			};


	private : 

			std::map<std::string, double>	_map;
			std::string						*_tab;
			int								_tabLen;
			bool							_gate;
};





#endif