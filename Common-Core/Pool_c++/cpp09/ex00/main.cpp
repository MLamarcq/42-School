#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error, can not open file" << std::endl;
		return (0);
	}
	try
	{
		std::string str(argv[1]);
		Bitcoin bitcoin;
		bitcoin.open_and_save_input(str);
		// bitcoin.parse_tab_date();
		// bitcoin.parse_pipe_tab();
		// bitcoin.check_number();
		bitcoin.do_program();
	}
	catch (Bitcoin::ErrorOpeningFileException &e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	catch (Bitcoin::WrongFileFormatException &e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	catch (Bitcoin::WrongDateFormatException &e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	catch (std::out_of_range &e)
	{
	}
	return (0);
}