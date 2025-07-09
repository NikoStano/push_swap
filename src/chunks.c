/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 08:06:00 by nistanoj          #+#    #+#             */
/*   Updated: 2025/07/09 08:57:33 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int  count_leq(t_stack *a, int pivot)
{
    int cnt = 0;
    t_node *cur = a->top;
    while (cur)
    {
        if (cur->value <= pivot)
            cnt++;
        cur = cur->next;
    }
    return (cnt);
}

void	push_chunk_to_b(t_stack *a, t_stack *b, int pivot)
{
	int	count;
	int	to_push;

	count = 0;
	to_push = count_leq(a, pivot);
	while (count < to_push)
	{
		if (a->top->value <= pivot)
		{
			op_pb(a, b);
			count++;
		}
		else
			op_ra(a);
	}
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int		max;
	int		pos;
	int		i;
	t_node	*cur;

	while (b->size > 0)
	{
		cur = b->top;
		max = cur->value;
		pos = 0;
		i = 0;
		while (cur)
		{
			if (cur->value > max)
			{
				max = cur->value;
				pos = i;
			}
			cur = cur->next;
			i++;
		}
		if (pos <= b->size / 2)
			while (b->top->value != max)
				op_rb(b);
		else
			while (b->top->value != max)
				op_rrb(b);
		op_pa(a, b);
	}
}
