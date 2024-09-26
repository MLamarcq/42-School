/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:57:21 by mael              #+#    #+#             */
/*   Updated: 2023/09/08 11:57:19 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>
#include <string>

class Contact
{
	
	public :
	
		Contact(void);
		~Contact(void);
		int		fill_contact(Contact *Contact);
		void	print_contact(int i) const;
		void	print_inside_contact(int i) const ;
		int		fill_names(Contact *Contact, std::string str, int i);
		int		fill_phone_number(Contact *Contact, std::string str, int i);


	private :
	
		std::string _FirstName;
		std::string _LastName;
		std::string _NickName;
		std::string _PhoneNumber;
		std::string _DarkestSecret;
};

#endif