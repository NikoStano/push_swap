/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 08:05:34 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/08 21:50:55 by nistanoj         ###   ########.fr       */
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
	a->index = 0;
}

int	find_chunk_pos(t_stack *a, t_stack *sorted, int low, int high)
{
	t_node	*cur;
	int		idx;
	int		i;

	i = 0;
	cur = a->top;
	while (cur)
	{
		idx = get_indexed(cur, sorted);
		if (idx >= low && idx <= high)
			return (i);
		cur = cur->next;
		i++;
	}
	return (-1);
}

int	find_max_pos(t_stack *b, t_stack *sorted)
{
	t_node	*cur;
	int		max_idx;
	int		pos;
	int		idx;
	int		cur_idx;

	max_idx = -1;
	pos = 0;
	idx = 0;
	cur_idx = 0;
	cur = b->top;
	while (cur)
	{
		cur_idx = get_indexed(cur, sorted);
		if (cur_idx < 0)
			return (-1);
		if (cur_idx > max_idx)
		{
			max_idx = cur_idx;
			pos = idx;
		}
		cur = cur->next;
		idx++;
	}
	return (pos);
}

// void	print_stack(t_stack *st)
// {
// 	t_node	*cur;

// 	cur = st->top;
// 	printf("Stack : ");
// 	while (cur)
// 	{
// 		printf("%d ", cur->value);
// 		cur = cur->next;
// 	}
// 	printf("\n");
// }
