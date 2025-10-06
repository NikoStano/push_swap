/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 08:05:42 by nistanoj          #+#    #+#             */
/*   Updated: 2025/10/05 01:28:37 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three(t_stack *st)
{
	int	one;
	int	two;
	int	thr;

	one = st->top->value;
	two = st->top->next->value;
	thr = st->top->next->next->value;
	if (one > two && two < thr && one < thr)
		op_sa(st);
	else if (one > two && two > thr)
	{
		op_sa(st);
		op_rra(st);
	}
	else if (one > two && two < thr && one > thr)
		op_ra(st);
	else if (one < two && two > thr && one < thr)
	{
		op_sa(st);
		op_ra(st);
	}
	else if (one < two && two > thr && one > thr)
		op_rra(st);
}

static void	sort_ff(t_stack *a, t_stack *b)
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

static void	sort_four(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		sort_ff(a, b);
	sort_three(a);
	while (b->size > 0)
		op_pa(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			op_sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_four(a, b);
}
