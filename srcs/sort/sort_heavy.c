/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_heavy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:40:37 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/08 21:53:04 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	last_back(t_stack *a, t_stack *b, t_stack *sorted, int low)
{
	int	idx;

	idx = get_indexed(a->top, sorted);
	op_pb(a, b);
	a->pushed++;
	if (b->size > 1 && idx <= low + (a->chunk_size / 2))
		op_rb(b);
}

static void	rotate_a_to_top(t_stack *a, int pos)
{
	int	k;

	k = 0;
	if (pos > a->size / 2)
	{
		k = a->size - pos;
		while (k-- > 0)
			op_rra(a);
	}
	else
	{
		while (pos-- > 0)
			op_ra(a);
	}
}

static void	push_chunk_to_b(t_stack *a, t_stack *b, t_stack *sorted)
{
	int	chunk_count;
	int	pos;
	int	low;
	int	high;
	int	k;

	k = 0;
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
		rotate_a_to_top(a, pos);
		last_back(a, b, sorted, low);
		chunk_count++;
	}
}

static void	push_back_to_a(t_stack *a, t_stack *b, t_stack *sorted)
{
	int	pos;
	int	k;

	k = 0;
	pos = find_max_pos(b, sorted);
	if (pos > b->size / 2)
	{
		k = b->size - pos;
		while (k-- > 0)
			op_rrb(b);
	}
	else
	{
		while (pos-- > 0)
			op_rb(b);
	}
	op_pa(a, b);
}

int	sort_heavy(t_stack *a, t_stack *b)
{
	t_stack	*sorted;
	int		total_chunks;

	sorted = create_stack(a);
	if (!sorted)
		return (1);
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
