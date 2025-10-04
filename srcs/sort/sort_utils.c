/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:19:30 by nistanoj          #+#    #+#             */
/*   Updated: 2025/10/04 21:33:08 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_up(t_stack *st, int size)
{
	int	i;

	i = st->size - size;
	if ((st->size / 2) < size)
	{
		while (i-- > 0)
			op_rra(st);
	}
	else
	{
		while (size-- > 0)
			op_ra(st);
	}
}

int	get_indexed(t_list *a, t_stack *sorted)
{
	t_list	*j;
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

static int	find_max_pos(t_stack *b, t_stack *sorted)
{
	t_list	*cur;
	int		max_idx;
	int		pos;
	int		idx;
	int		cur_idx;

	max_idx = -1;
	pos = 0;
	idx = 0;
	cur_idx = 0;
	cur = b->top;
	while (cur)
	{
		cur_idx = get_indexed(cur, sorted);
		if (cur_idx < 0)
			return (-1);
		if (cur_idx > max_idx)
		{
			max_idx = cur_idx;
			pos = idx;
		}
		cur = cur->next;
		idx++;
	}
	return (pos);
}

void	push_back_to_a(t_stack *a, t_stack *b, t_stack *sorted)
{
	int	pos;
	int	k;

	pos = find_max_pos(b, sorted);
	k = b->size - pos;
	if (pos > k)
	{
		while (k-- > 0)
			op_rrb(b);
	}
	else
	{
		while (pos-- > 0)
			op_rb(b);
	}
	op_pa(a, b);
}
