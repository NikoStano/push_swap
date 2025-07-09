/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 08:05:42 by nistanoj          #+#    #+#             */
/*   Updated: 2025/07/09 08:18:07 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_small(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	if (a->size == 2)
		op_sa(a);
	if (a->size == 3)
	{
		x = a->top->value;
		y = a->top->next->value;
		z = a->top->next->next->value;
		if (x > y && y < z && x < z)
			op_sa(a);
		else if (x > y && y > z)
		{
			op_sa(a);
			op_rra(a);
		}
		else if (x > y && y < z && x > z)
			op_ra(a);
		else if (x < y && y > z && x < z)
		{
			op_sa(a);
			op_ra(a);
		}
		else if (x < y && y > z && x > z)
			op_rra(a);
	}
}
