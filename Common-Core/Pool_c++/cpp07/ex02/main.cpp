#include "Array.class.hpp"
#include <iostream>

int main()
{
	std::srand(time(0));
	Array<int> array(3);
	Array<int> array2(1);
	Array<char> array3(15);
	Array<int> array4(100);
	

	std::cout << "array size = " << array.size() << std::endl;
	std::cout << "array size 2 = " << array2.size() << std::endl;
	std::cout << "array size 3 = " << array3.size() << std::endl;

	for(unsigned int i = 0; i < array.size(); i++)
	{
		array[i] = rand();
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	}
	std::cout << std::endl;
	
	for(unsigned int i = 0; i < array2.size(); i++)
	{
		array2[i] = rand();
		std::cout << "array2[" << i << "] = " << array2[i] << std::endl;
	}
	std::cout << std::endl;
	
	for(unsigned int i = 0; i < array3.size(); i++)
	{
		array3[i] = (rand() % 256);
		std::cout << "array3[" << i << "] = " << static_cast<int>(array3[i]) << std::endl;
	}
	std::cout << std::endl;
	
	for(unsigned int i = 0; i < array4.size(); i++)
	{
		array4[i] = (rand());
		std::cout << "array4[" << i << "] = " << array4[i] << std::endl;
	}
	std::cout << std::endl;
	
	array3[4] = 'a';
	for(unsigned int i = 0; i < array3.size(); i++)
	{
		std::cout << "array3[" << i << "] = " << static_cast<int>(array3[i]) << std::endl;
	}
	std::cout << std::endl;

	int index;
	try
	{
		index = -4;
		std::cout << "array[" << index << "] = " << array[index] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		index = 12;
		std::cout << "array[" << index << "] = " << array[index] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		index = 1;
		std::cout << "array[" << index << "] = " << array[index] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		index = -32;
		std::cout << "array4[" << index << "] = " << array4[index] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		index = 54;
		std::cout << "array4[" << index << "] = " << array4[index] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		index = 155;
		std::cout << "array4[" << index << "] = " << array4[index] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

/****************************************************************************/

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//         std::cout << "Numbers[" << i << "] = " << numbers[i] << std::endl;
//     }
//     delete [] mirror;//
//     return 0;
// }
