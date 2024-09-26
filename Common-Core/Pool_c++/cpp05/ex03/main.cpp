#include "AForm.class.hpp"
#include "Bureaucrat.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "Intern.class.hpp"

int main()
{
	std::srand(std::time(0));
	Intern intern1;
	Bureaucrat b1("Francis", 1);
	AForm *form1 = intern1.makeForm("Shrubbery creation form", "Daniel");

	form1->beSigned(b1);

	form1->execute(b1);

	delete form1;

	return (0);
}