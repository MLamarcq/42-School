#include "template.hpp"


int main ()
{
	// int a = 2;
	// int b = 3;
	
	// ::swap( a, b );
	// std::cout << "a = " << a << ", b = " << b << std::endl;
	// std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	// std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	// std::string c = "chaine1";
	// std::string d = "chaine2";
	// ::swap(c, d);
	// std::cout << "c = " << c << ", d = " << d << std::endl;
	// std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	// std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	/*****************************************************************/
	
	
	int a = 2;
	int b = 3;

	std::cout << "Avant : ";
	std::cout << "a = " << a;
	std::cout << " et b = " << b << std::endl;

	std::cout << "On swap." << std::endl;
	::swap(a, b);
	
	std::cout << "Apres : ";
	std::cout << "a = " << a;
	std::cout << " et b = " << b << std::endl;

	std::cout << std::endl;

	char c = 'c';
	char d = 'd';

	std::cout << "Avant : ";
	std::cout << "c = " << c;
	std::cout << " et d = " << d << std::endl;

	std::cout << "On swap." << std::endl;
	::swap(c, d);
	
	std::cout << "Apres : ";
	std::cout << "c = " << c;
	std::cout << " et d = " << d << std::endl;


	std::cout << std::endl;

	float flt1 = 42.12f;
	float flt2 = 103.2f;

	std::cout << "Avant : ";
	std::cout << "flt1 = " << flt1;
	std::cout << " et flt2 = " << flt2 << std::endl;

	std::cout << "On swap." << std::endl;
	::swap(flt1, flt2);
	
	std::cout << "Apres : ";
	std::cout << "flt1 = " << flt1;
	std::cout << " et flt2 = " << flt2 << std::endl << std::endl;

	std::cout << "###############################" << std::endl << std::endl;

	int nb = 155;
	int nb1 = 203;

	std::cout << "nb = " << nb << " et nb1 = " << nb1 << std::endl;
	std::cout << "Le max = " << ::max(nb, nb1) << std::endl;
	std::cout << "Le min = " << ::min(nb, nb1) << std::endl << std::endl;

	nb = 30;
	nb1 = 30;

	std::cout << "nb = " << nb << " et nb1 = " << nb1 << std::endl;
	std::cout << "Le max 2 = " << ::max(nb, nb1) << std::endl;
	std::cout << "Le min 2 = " << ::min(nb, nb1) << std::endl << std::endl;

	nb = 12;
	nb1 = 15;

	std::cout << "nb = " << nb << " et nb1 = " << nb1 << std::endl;
	std::cout << "Le max 3 = " << ::max(nb, nb1) << std::endl;
	std::cout << "Le min 3 = " << ::min(nb, nb1) << std::endl << std::endl;

	std::cout << "###############################" << std::endl << std::endl;

	std::string str = "Salut";
	std::string str2 = "Bonjour";

	std::cout << "Min = " << ::min(str, str2) << std::endl;
	std::cout << "Max = " << ::max(str, str2) << std::endl;


	return (0);
}




