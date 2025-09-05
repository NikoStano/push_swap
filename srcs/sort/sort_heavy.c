/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_heavy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:40:37 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/05 18:03:56 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_heavy(t_stack *a, t_stack *b)
{
	t_stack	*indexed;

	(void)b;
	indexed = malloc(sizeof(t_stack));
	if (!indexed)
		return (1);
	stack_init(indexed);
	if (index_list_a(a, indexed))
		return (list_clear(&indexed->top), free(indexed), 1);
	list_clear(&indexed->top);
	free(indexed);
	return (0);
}
