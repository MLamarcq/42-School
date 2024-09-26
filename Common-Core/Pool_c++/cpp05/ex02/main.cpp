#include "AForm.class.hpp"
#include "Bureaucrat.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"

int main()
{
	std::srand(std::time(0));
	// AForm *form1 = new ShrubberyCreationForm("Garden");
	// AForm *form2 = new RobotomyRequestForm("Boss");
	// PresidentialPardonForm form3("Silvie");
	
	// Bureaucrat b1("Daniel", 1);

	// std::cout << std::endl;
	// std::cout << b1 << std::endl;

	// form1->beSigned(b1);
	// form1->execute(b1);

	// std::cout << std::endl;

	// form2->beSigned(b1);
	// form2->execute(b1);

	// std::cout << std::endl;

	// form3.beSigned(b1);
	// form3.execute(b1);

	// std::cout << std::endl;

	// delete form1;
	// delete form2;

	// return (0);

	/*********************************************************/

	// AForm *form1 = new ShrubberyCreationForm("Garden");
	// AForm *form2 = new RobotomyRequestForm("Boss");
	// PresidentialPardonForm form3("Silvie");
	
	// Bureaucrat b1("Franck", 50);

	// std::cout << std::endl;
	// std::cout << b1 << std::endl;

	// form1->beSigned(b1);
	// form1->execute(b1);

	// std::cout << std::endl;

	// form2->beSigned(b1);
	// form2->execute(b1);

	// std::cout << std::endl;

	// form3.beSigned(b1);
	// form3.execute(b1);

	// std::cout << std::endl;

	// delete form1;
	// delete form2;

	// return (0);

	/*********************************************************/


	AForm *form1 = new ShrubberyCreationForm("Garden");
	AForm *form2 = new RobotomyRequestForm("Boss");
	PresidentialPardonForm form3("Silvie");
	
	Bureaucrat b1("Franck", 120);
	Bureaucrat b2("Jojo", 1);

	std::cout << std::endl;
	std::cout << b1 << std::endl;

	form1->beSigned(b1);
	form1->execute(b1);

	std::cout << std::endl;

	form2->beSigned(b1);
	form2->execute(b1);

	std::cout << std::endl;

	form3.beSigned(b1);
	form3.execute(b1);

	std::cout << std::endl;

	b1.executeForm(form3);

	std::cout << std::endl;

	form3.beSigned(b2);
	b2.executeForm(form3);
	
	std::cout << std::endl;

	b1.executeForm(form3);

	std::cout << std::endl;

	delete form1;
	delete form2;

	return (0);
}