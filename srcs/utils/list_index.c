/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:14:35 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/08 21:42:04 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	copy_array(t_stack *dst, t_stack *src)
{
	t_node	*n_lst;
	t_node	*curr;

	curr = src->top;
	dst->size = 0;
	while (curr)
	{
		n_lst = list_new(curr->value);
		if (!n_lst)
			return (list_clear(&dst->top), 1);
		list_add_back(&dst->top, n_lst);
		dst->size++;
		curr = curr->next;
	}
	return (0);
}

void	bubble_sort(t_stack *sorted)
{
	int		i;
	int		j;
	int		tmp;
	t_node	*first;

	i = 0;
	first = sorted->top;
	while (i < sorted->size)
	{
		j = 0;
		sorted->top = first;
		while (j < sorted->size - i - 1)
		{
			if (sorted->top->value < sorted->top->next->value)
			{
				tmp = sorted->top->value;
				sorted->top->value = sorted->top->next->value;
				sorted->top->next->value = tmp;
			}
			j++;
			sorted->top = sorted->top->next;
		}
		i++;
	}
}

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

int	index_list_a(t_stack *a)
{
	t_stack	*sorted;
	t_node	*first;

	first = a->top;
	sorted = malloc(sizeof(t_stack));
	if (!sorted)
		return (1);
	stack_init(sorted);
	if (copy_array(sorted, a))
		return (free(sorted), 1);
	if (get_indexed(first, sorted))
	{
		list_clear(&sorted->top);
		return (free(sorted), 1);
	}
	list_clear(&sorted->top);
	return (free(sorted), 0);
}
