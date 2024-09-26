#include "C.class.hpp"

Base *generate(void)
{
	Base *base = NULL;
	int time = std::rand();
	if (time % 2 == 0)
		base = new A;
	else if (time % 3 == 0)
		base = new B;
	else
		base = new C;
	
	return (base);
}

void	identify(Base *p)
{
	A *child1 = dynamic_cast<A*>(p);
	B *child2 = dynamic_cast<B*>(p);
	C *child3 = dynamic_cast<C*>(p);

	if (child1 != NULL)
		std::cout << "We have an A !" << std::endl;
	if (child2 != NULL)
		std::cout << "We have a B !" << std::endl;
	if (child3 != NULL)
		std::cout << "We have a C !" << std::endl;
	return ;
}

void	identify(Base &p)
{
	try
	{
		A & child1 = dynamic_cast<A &>(p);
		(void)child1;
		std::cout << "This is an A !" << std::endl;
	}
	catch (std::exception &bc)
	{
		std::cerr << "This is not a A : " << bc.what() << std::endl;
	}
	try
	{
		B & child2 = dynamic_cast<B &>(p);
		(void)child2;
		std::cout << "This is a B !" << std::endl;
	}
	catch (std::exception &bc)
	{
		std::cerr << "This is not a B : " << bc.what() << std::endl;
	}
	try
	{
		C & child3 = dynamic_cast<C &>(p);
		(void)child3;
		std::cout << "This is a C !" << std::endl;
	}
	catch (std::exception &bc)
	{
		std::cerr << "This is not a C : " << bc.what() << std::endl;
	}
	return ;
}

int main()
{
	std::srand(std::time(0));
	
	Base *base = generate();

	identify(base);

	std::cout << std::endl;

	identify(*base);
	
	delete base;
	
	return (0);
}