/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_two.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:02:51 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/05 15:04:04 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
