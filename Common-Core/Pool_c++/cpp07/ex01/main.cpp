#include "Iter.hpp"

int main ()
{
	int tab[] = {3, 4, 5, 6};
	::Iter(tab, 4, ::print_tab<int>);
	std::cout << std::endl;
	
	Iter(tab, 4, increase<int>);
	Iter(tab, 4, print_tab<int>);
	std::cout << std::endl;

	::Iter(tab, 4, ::decrease<int>);
	::Iter(tab, 4, ::print_tab<int>);
	std::cout << std::endl;


	char str[] = "Salut les gars";
	::Iter(str, 14, ::print_tab<char>);
	std::cout << std::endl;

	const char *str1;
	str1 = "Salut";
	::Iter(str1, 5, ::print_tab<const char>);
	std::cout << std::endl;


	int *a = new int[20];

	for(int i = 0; i < 20; i++)
		a[i] = i;
	Iter(a, 20, print_tab<int>);
	std::cout << std::endl;

	for(int j = 0; j < 100 ; j++)
		Iter(a, 20, increase<int>);
	Iter(a, 20, print_tab<int>);
	std::cout << std::endl;
	
	for(int j = 0; j < 100 ; j++)
		Iter(a, 20, decrease<int>);
	Iter(a, 20, print_tab<int>);
	std::cout << std::endl;
	
	delete [] a;
	return (0);
}