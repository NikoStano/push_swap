/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:14:35 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/09 16:56:35 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_indexed(t_node *a, t_stack *sorted)
{
	t_node	*j;
	int		idx;

	idx = 0;
	j = sorted->top;
	while (j)
	{
		if (a->value > j->value)
			idx++;
		j = j->next;
	}
	return (idx);
}

// int	index_list_a(t_stack *a)
// {
// 	t_stack	*sorted;
// 	t_node	*first;

// 	first = a->top;
// 	sorted = malloc(sizeof(t_stack));
// 	if (!sorted)
// 		return (1);
// 	stack_init(sorted);
// 	if (copy_list(sorted, a))
// 		return (free(sorted), 1);
// 	if (get_indexed(first, sorted))
// 	{
// 		list_clear(&sorted->top);
// 		return (free(sorted), 1);
// 	}
// 	list_clear(&sorted->top);
// 	return (free(sorted), 0);
// }
