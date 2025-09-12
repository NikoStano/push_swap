/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_two.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:02:51 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/12 21:19:05 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
