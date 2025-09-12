/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_one.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 08:05:10 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/12 21:19:17 by nistanoj         ###   ########.fr       */
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
