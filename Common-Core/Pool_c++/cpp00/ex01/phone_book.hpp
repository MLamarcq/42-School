/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:29:55 by mael              #+#    #+#             */
/*   Updated: 2023/09/08 12:03:39 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "contact.class.hpp"
#include "phone_book.class.hpp"
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <stdlib.h>


//utils.cpp
int	is_digit(std::string str);
int	is_letter(std::string str);
int ft_strncmp(std::string str1, std::string str2, int n);
int ft_strlen(std::string str);
int	check_char(std::string str, int n);

//start_phone_book.cpp
int	start_phone_book(Contact Contact);


#endif