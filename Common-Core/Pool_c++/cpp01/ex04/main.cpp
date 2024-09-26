/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:28:11 by mael              #+#    #+#             */
/*   Updated: 2023/09/13 11:49:05 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	size_t pos;
	int i = 0;
	std::string dest;
	std::string content_f1;
	
	if (argc != 4)
	{
		std::cout << "Wrong args." << std::endl;
		std::cout << "To run the program, use : ";
		std::cout << "./file 'a file' 'a string you choose' 'another string'. ";
		std::cout << "\n";
	}
	else
	{
		std::string s1(argv[2]);
		std::string s2(argv[3]);
		
		std::string test(argv[1]);
		std::string name_newFile = test.append(".replace");
		std::ifstream myfile(argv[1]);
		
		if (!myfile)
		{
			std::cerr << "File does not exist. Please choose another" << std::endl;
			return (1);
		}
		std::ofstream mydest(name_newFile.c_str());
		if (!mydest)
		{
			std::cerr << "Error duriing opening file" << std::endl;
			return (1);
		}
		while (std::getline(myfile, dest))
		{
			content_f1 = content_f1 + dest;
			content_f1 = content_f1 + '\n';
			pos = content_f1.find(s1);
			if (pos != std::string::npos)
			{
				content_f1.erase(pos, s1.length());
				content_f1.insert(pos, s2);
				i++;
			}
		}
		if (i == 0)
		{
			std::cout << "The word you are trying to find does not exist ";
			std::cout << "in this file." << std::endl;
		}
		mydest << content_f1;
	}
	return (0);
}
