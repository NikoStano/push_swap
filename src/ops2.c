/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:19:32 by nistanoj          #+#    #+#             */
/*   Updated: 2025/07/09 11:25:24 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
