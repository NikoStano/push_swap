/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:19:30 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/10 20:35:04 by nistanoj         ###   ########.fr       */
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

void	push_to_b(t_stack *a, t_stack *b)
{
	int		i;
	int		tmp;
	int		pos;
	t_list	*first;

	i = 0;
	tmp = a->top->value;
	pos = 0;
	first = a->top;
	while (a->top)
	{
		if (a->top->value < tmp)
		{
			i = pos;
			tmp = a->top->value;
		}
		a->top = a->top->next;
		pos++;
	}
	a->top = first;
	rotate_up(a, i);
	op_pb(a, b);
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

	k = 0;
	pos = find_max_pos(b, sorted);
	if (pos > b->size / 2)
	{
		k = b->size - pos;
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
