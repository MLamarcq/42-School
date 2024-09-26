#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

int main()
{
	Form form1("Worker's form", 55, 40);
	Form form2("Boss's form", 1, 1);
	Form form3("Manager's form", 25, 25);
	Bureaucrate b1("Marcel", 154);
	Bureaucrate b2("Franck", 48);
	Bureaucrate b3("Emilien", 2);
	std::cout << std::endl;
	
	std::cout << form1 << std::endl;
	
	form1.beSigned(b1);
	
	std::cout << form1 << std::endl;
	
	form1.beSigned(b2);

	std::cout << form1 << std::endl;

	form1.beSigned(b3);

	std::cout << form1 << std::endl;

	form2.beSigned(b3);
	std::cout << form1 << std::endl;
	
	
	b3.exec_form(form1);
	b1.exec_form(form1);
	b3.signForm(form1);
	b3.signForm(form2);
	b3.signForm(form3);
	return (0);
}