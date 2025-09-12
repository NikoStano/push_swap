/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:04:19 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/12 21:19:31 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
	write(1, "ss\n", 3);
}

void	op_rr(t_stack *a, t_stack *b)
{
	stack_rotate(a);
	stack_rotate(b);
	write(1, "rr\n", 3);
}

void	op_rrr(t_stack *a, t_stack *b)
{
	stack_reverse_rotate(a);
	stack_reverse_rotate(b);
	write(1, "rrr\n", 4);
}
