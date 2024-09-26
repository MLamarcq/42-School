#include "ScalarConvert.class.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "You need two argument to lauch the program :";
		std::cerr << " ./Scarlarconvert + a string of your choice." << std::endl;
		return (0);
	}
	else
	{
		std::string const str(argv[1]);
		ScalarConvert::DisplayAll(str);
	}
	return (0);
}