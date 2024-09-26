#include "Span.class.hpp"

int main()
{

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << std::endl;
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (Span::NotDistanceException &e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	catch (Span::EmptyArrayException &e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}

	/************************************************************/

	// std::srand(unsigned (std::time(0)));
	// Span sp(10);

	// sp.Generate();

	// std::cout << std::endl;
	// try
	// {
	// 	std::cout << sp.longestSpan() << std::endl;
	// 	std::cout << sp.shortestSpan() << std::endl;
	// }
	// catch (Span::NotDistanceException &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// 	return (0);
	// }
	// catch (Span::EmptyArrayException &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// 	return (0);
	// }
	// sp.Generate();
	// sp.insertAll();
	// for (std::vector<int>::const_iterator it = sp.getBegin(); it != sp.getEnd(); it++)
	// {
	// 	std::cout << *it << std::endl;
	// }

	/************************************************************/
	
	// std::srand(unsigned (std::time(0)));
	// Span sp(100);

	// sp.Generate();
	
	// std::cout << std::endl;
	// try
	// {
	// 	std::cout << sp.longestSpan() << std::endl;
	// 	std::cout << sp.shortestSpan() << std::endl;
	// }
	// catch (Span::NotDistanceException &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// 	return (0);
	// }
	// catch (Span::EmptyArrayException &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// 	return (0);
	// }
	// sp.Generate();
	// sp.insertAll();
	// for (std::vector<int>::const_iterator it = sp.getBegin(); it != sp.getEnd(); it++)
	// {
	// 	std::cout << *it << std::endl;
	// }

	/************************************************************/
	
	// std::srand(unsigned (std::time(0)));
	// Span sp(10000);

	// sp.Generate();
	// std::cout << std::endl;
	// try
	// {
	// 	std::cout << sp.longestSpan() << std::endl;
	// 	std::cout << sp.shortestSpan() << std::endl;
	// }
	// catch (Span::NotDistanceException &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// 	return (0);
	// }
	// catch (Span::EmptyArrayException &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// 	return (0);
	// }
	// // sp.Generate();
	// // sp.Generate();
	// sp.insertAll();
	// for (std::vector<int>::const_iterator it = sp.getBegin(); it != sp.getEnd(); it++)
	// {
	// 	std::cout << *it << std::endl;
	// }
	return (0);
}