/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:19:30 by nistanoj          #+#    #+#             */
/*   Updated: 2025/10/04 22:18:02 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_init(t_stack *st)
{
	st->top = NULL;
	st->size = 0;
	st->chunk_size = 0;
	st->chunk = 0;
	st->pushed = 0;
}

void	rotate_up(t_stack *st, int size)
{
	int	rev_size;

	if (size == 0)
		return ;
	rev_size = st->size - size;
	if (size <= rev_size)
	{
		while (size-- > 0)
			op_ra(st);
	}
	else
	{
		while (rev_size-- > 0)
			op_rra(st);
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
	int	rev_pos;

	pos = find_max_pos(b, sorted);
	rev_pos = b->size - pos;
	if (pos <= rev_pos)
	{
		while (pos-- > 0)
			op_rb(b);
	}
	else
	{
		while (rev_pos-- > 0)
			op_rrb(b);
	}
	op_pa(a, b);
}
