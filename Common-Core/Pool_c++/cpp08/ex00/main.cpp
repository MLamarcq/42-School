#include "easyfind.class.hpp"

int main()
{
	std::list<int> lst;

	std::cout << "Easyfind with list" << std::endl << std::endl;
	std::cout << "First try with empty list : ";
	easyfind(lst, 4);
	fillContainer(lst, 10);
	
	std::cout << std:: endl << "Second try : ";
	easyfind(lst, 4);
	fillContainer(lst, 10);

	std::cout << std:: endl << "Third try : ";
	easyfind(lst, 25);
	fillContainer(lst, 10);

	std::cout << std:: endl << "Fourth try : ";
	easyfind(lst, 25);

	std::cout << std::endl << "###################################" << std::endl << std::endl;


	std::vector<int> vect;
	std::cout << "Easyfind with vector" << std::endl << std::endl;
	
	std::cout << "First try with empty vector : ";
	easyfind(vect, 8);
	fillContainer(vect, 10);
	
	std::cout << std:: endl << "Second try : ";
	easyfind(vect, 13);
	fillContainer(vect, 10);

	std::cout << std:: endl << "Third try : ";
	easyfind(vect, 13);
	fillContainer(vect, 10);

	std::cout << std:: endl << "Fourth try : ";
	easyfind(vect, 25);
	
	return (0);

}

