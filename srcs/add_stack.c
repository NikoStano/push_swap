/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:28:25 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/05 15:00:41 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_size(char **av)
{
	int	i;

	i = 1;
	while (av[i])
		i++;
	return (i);
}

static t_node	*list_new(int val)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = val;
	new->next = NULL;
	return (new);
}

static t_node	*listlast(t_node *top)
{
	if (!top)
		return (NULL);
	while (top->next)
		top = top->next;
	return (top);
}

static void	list_add_back(t_node **top, t_node *new)
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

void	add_stack(char **av, t_stack *st)
{
	int		i;
	t_node	*new;

	st->size = (get_size(av) - 1);
	i = 0;
	while (i < st->size)
	{
		if (av[i] && av[i + 1])
		{
			new = list_new(ft_atoi(av[i + 1]));
			list_add_back(&st->top, new);
		}
		i++;
	}
}
