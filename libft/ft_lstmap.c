/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:14:34 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/10 20:30:39 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*nlst;
	t_list	*elem;
	int		ncont;

	nlst = NULL;
	while (lst)
	{
		ncont = f(lst->value);
		if (!ncont)
		{
			ft_lstclear(&nlst, del);
			return (NULL);
		}
		elem = ft_lstnew(ncont);
		if (!elem)
		{
			ft_lstclear(&nlst, del);
			del(ncont);
			return (NULL);
		}
		ft_lstadd_back(&nlst, elem);
		lst = lst->next;
	}
	return (nlst);
}
