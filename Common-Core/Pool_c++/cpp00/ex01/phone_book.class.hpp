/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:18:02 by mael              #+#    #+#             */
/*   Updated: 2023/09/07 15:20:46 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONE_BOOK_CLASS_HPP
# define PHONE_BOOK_CLASS_HPP

#include <iostream>
#include "contact.class.hpp"

class PhoneBook
{
	public :
		
		PhoneBook(void);
		~PhoneBook(void);
		int		start_phone_book(Contact Contact, PhoneBook PhoneBook);
		int		add_contact(Contact Contact);
		void	essai(Contact Contact);
		void	display_all(Contact Contact) const;
		int		nb_contact() const;
		void	display_contact(int index) const;



	private : 

		int	_index;
		int	_nbr_contact;
		Contact _contact[8];
};

#endif