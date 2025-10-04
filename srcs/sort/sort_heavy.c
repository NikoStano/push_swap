/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_heavy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:40:37 by nistanoj          #+#    #+#             */
/*   Updated: 2025/10/04 20:26:49 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_chunk(t_stack *a)
{
	if (a->size <= 100)
		a->chunk_size = a->size / 5 + 1;
	else
		a->chunk_size = a->size / 10 + 1;
	a->chunk = 0;
	a->pushed = 0;
	a->index = 0;
}

static int	find_chunk_pos(t_stack *a, t_stack *sorted, int low, int high)
{
	t_stack	*cur;
	int		idx;
	int		i;
	t_list	*first;

	i = 0;
	cur = copy_stack(a);
	if (!cur)
		error_exit();
	first = cur->top;
	while (cur->top)
	{
		idx = get_indexed(cur->top, sorted);
		if (idx >= low && idx <= high)
		{
			list_clear(&first);
			return (free(cur), i);
		}
		cur->top = cur->top->next;
		i++;
	}
	list_clear(&first);
	return (free(cur), -1);
}

static void	last_back(t_stack *a, t_stack *b, t_stack *sorted, int low)
{
	int	idx;

	idx = get_indexed(a->top, sorted);
	op_pb(a, b);
	a->pushed++;
	if (b->size > 1 && idx <= low + (a->chunk_size / 2))
		op_rb(b);
}

static void	push_chunk_to_b(t_stack *a, t_stack *b, t_stack *sorted)
{
	int	chunk_count;
	int	pos;
	int	low;
	int	high;

	pos = 0;
	chunk_count = 0;
	while (chunk_count < a->chunk_size)
	{
		low = a->chunk * a->chunk_size;
		high = low + a->chunk_size - 1;
		if (high >= sorted->size)
			high = sorted->size - 1;
		pos = find_chunk_pos(a, sorted, low, high);
		if (pos == -1)
			break ;
		rotate_up(a, pos);
		last_back(a, b, sorted, low);
		chunk_count++;
	}
}

int	sort_heavy(t_stack *a, t_stack *b)
{
	t_stack	*sorted;
	int		total_chunks;

	sorted = sorted_stack(a);
	if (!sorted)
		return (1);
	bubble_sort(sorted);
	init_chunk(a);
	total_chunks = (sorted->size + a->chunk_size - 1) / a->chunk_size;
	while (a->chunk < total_chunks && a->size > 0)
	{
		push_chunk_to_b(a, b, sorted);
		a->chunk++;
	}
	while (b->size > 0)
		push_back_to_a(a, b, sorted);
	list_clear(&sorted->top);
	free(sorted);
	return (0);
}
