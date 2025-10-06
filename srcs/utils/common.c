/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 00:59:14 by nistanoj          #+#    #+#             */
/*   Updated: 2025/10/05 01:04:10 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	init_stacks(t_stack **a, t_stack **b)
{
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	if (!*a || !*b)
	{
		if (*a)
			free(*a);
		if (*b)
			free(*b);
		return (1);
	}
	return (0);
}

void	clean_up(t_stack *a, t_stack *b, char **splited, int need_free)
{
	if (a)
	{
		list_clear(&a->top);
		free(a);
	}
	if (b)
		free(b);
	if (need_free && splited)
		ft_free_sp(splited);
}
