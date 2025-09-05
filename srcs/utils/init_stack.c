/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:28:25 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/05 18:36:29 by nistanoj         ###   ########.fr       */
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
