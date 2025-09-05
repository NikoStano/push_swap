/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_one.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 08:05:10 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/05 15:04:49 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
