#include "MutantStack.class.hpp"

int main()
{

	MutantStack<int> mstack;
	
	std::cout << "Exemple with MutantStack" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "mstack top = " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack size = " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	//Test pour montrer la difference
	// MutantStack<int>::iterator it2 = s.begin();
	// MutantStack<int>::iterator ite2 = s.end();
	// while (it2 != ite2)
	// {
	//     std::cout << *it2 << std::endl;
	//     ++it2;
	// }

	std::cout << "/*******************************************/" << std::endl;

	std::cout << "Exemple with std::vector" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "lst back = " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "lst size = " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator itb = lst.begin();
	std::list<int>::iterator iten = lst.end();
	++itb;
	--itb;
	while (itb != iten)
	{
		std::cout << *itb << std::endl;
		++itb;
	}

	std::cout << "/*******************************************/" << std::endl;

	std::cout << "Exemple with std::vector" << std::endl;
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(17);
	std::cout << "vec back = " << vec.back() << std::endl;
	vec.pop_back();
	std::cout << "vec size = " << vec.size() << std::endl;
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);
	vec.push_back(0);
	std::vector<int>::iterator itbe = vec.begin();
	std::vector<int>::iterator itend = vec.end();
	++itbe;
	--itbe;
	while (itbe !=  itend)
	{
		std::cout << *itbe << std::endl;
		++itbe;
	}
	return (0);
}