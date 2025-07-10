/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:27:58 by nistanoj          #+#    #+#             */
/*   Updated: 2025/07/09 13:08:20 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	stack_init(t_stack *st)
{
	st->top = NULL;
	st->size = 0;
}
