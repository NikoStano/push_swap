/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 08:05:10 by nistanoj          #+#    #+#             */
/*   Updated: 2025/07/09 08:05:25 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_stack *a, t_stack *b)
{
	if (b->size > 0)
		stack_push(a, stack_pop(b));
	write(1, "pa\n", 3);
}

void	op_pb(t_stack *a, t_stack *b)
{
	if (a->size > 0)
		stack_push(b, stack_pop(a));
	write(1, "pb\n", 3);
}

void	op_ra(t_stack *a)
{
	stack_rotate(a);
	write(1, "ra\n", 3);
}

void	op_rb(t_stack *b)
{
	stack_rotate(b);
	write(1, "rb\n", 3);
}

void	op_rr(t_stack *a, t_stack *b)
{
	stack_rotate(a);
	stack_rotate(b);
	write(1, "rr\n", 3);
}

void	op_rra(t_stack *a)
{
	stack_reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	op_rrb(t_stack *b)
{
	stack_reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	op_rrr(t_stack *a, t_stack *b)
{
	stack_reverse_rotate(a);
	stack_reverse_rotate(b);
	write(1, "rrr\n", 4);
}

void	op_sa(t_stack *a)
{
	stack_swap(a);
	write(1, "sa\n", 3);
}

void	op_sb(t_stack *b)
{
	stack_swap(b);
	write(1, "sb\n", 3);
}

void	op_ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
	write(1, "ss\n", 3);
}
