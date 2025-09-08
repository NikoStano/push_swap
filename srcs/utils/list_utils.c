/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:41:20 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/08 07:46:02 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*list_new(int val)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = val;
	new->next = NULL;
	return (new);
}

t_node	*listlast(t_node *top)
{
	if (!top)
		return (NULL);
	while (top->next)
		top = top->next;
	return (top);
}

void	list_add_back(t_node **top, t_node *new)
{
	t_node	*last;

	if (!top || !new)
		return ;
	if (!*top)
	{
		*top = new;
		return ;
	}
	last = listlast(*top);
	last->next = new;
}

void	list_delone(t_node *top)
{
	if (!top)
		return ;
	free(top);
}

void	list_clear(t_node **top)
{
	t_node	*tmp;

	if (!top || !*top)
		return ;
	while (*top)
	{
		tmp = (*top)->next;
		list_delone(*top);
		*top = tmp;
	}
}
