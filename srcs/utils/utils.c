/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 08:05:34 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/08 08:25:58 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_stack(t_stack *a)
{
	t_stack	*st;

	st = malloc(sizeof(t_stack));
	if (!st)
		return (NULL);
	stack_init(st);
	if (copy_array(st, a))
		return (free(st), NULL);
	bubble_sort(st);
	return (st);
}

void	init_chunk(t_stack *a)
{
	if (a->size <= 100)
		a->chunk_size = a->size / 5 + 1;
	else
		a->chunk_size = a->size / 11 + 1;
	a->chunk = 0;
	a->pushed = 0;
}

void	print_stack(t_stack *st)
{
	t_node	*cur;
	
	cur = st->top;
	printf("Stack après tri : ");
	while (cur)
	{
		printf("%d ", cur->value);
		cur = cur->next;
	}
	printf("\n");
}