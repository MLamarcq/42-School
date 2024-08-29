/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:00:44 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/05/26 11:09:54 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new;

	result = NULL;
	while (lst && f)
	{
		new = ft_lstnew(f(lst->content));
		if (!new->content)
		{
			ft_lstclear(&result, del);
			return (result);
		}
		ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	return (result);
}
