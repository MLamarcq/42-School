#include "Bureaucrat.class.hpp"

int main()
{
	Bureaucrate Tom("Tom", 5);
	Bureaucrate Brice("4565", 48);
	Bureaucrate Sandrine(Brice);
	Bureaucrate Salva ("Salva", 151);
	Bureaucrate Didier ("Didier", 0);

	std::cout << Tom << std::endl;
	std::cout << Brice << std::endl;
	std::cout << Sandrine << std::endl;
	std::cout << Salva << std::endl;
	std::cout << Didier << std::endl;

	Salva.DecreaseGrade();
	std::cout << Salva << std::endl;

	Didier.IncreaseGrade();
	std::cout << Didier << std::endl;

	Sandrine.DecreaseGrade();
	std::cout << Sandrine << std::endl;

	Tom.IncreaseGrade();
	std::cout << Tom << std::endl;

	return (0);
}