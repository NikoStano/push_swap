/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_heavy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:40:37 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/08 09:00:31 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_chunk_pos(t_stack *a, t_stack *sorted)
{
	t_node	*cur;
	int		idx;
	int		i;

	i = 0;
	cur = a->top;
	while (cur)
	{
		idx = get_indexed(cur, sorted);
		if (idx >= a->chunk * a->chunk_size && idx < (a->chunk + 1) * \
			a->chunk_size)
			return (i);
		cur = cur->next;
		i++;
	}
	return (-1);
}

static void	push_chunk_to_b(t_stack *a, t_stack *b, t_stack *sorted)
{
	int	pos;
	int	chunk_count;

	pos = 0;
	chunk_count = 0;
	while (chunk_count < a->chunk_size && a->pushed < a->size)
	{
		int min = a->chunk * a->chunk_size;
		int max = min + a->chunk_size;
		printf("Chunk %d: index [%d, %d]\n", a->chunk, min, max);
		pos = find_chunk_pos(a, sorted);
		if (pos == -1)
			break ;
		if (pos <= a->size / 2)
			while (pos-- > 0)
				op_ra(a);
		else
			while (pos++ < a->size)
				op_rra(a);
		printf("push %d (index %d) dans B\n", a->top->value, get_indexed(a->top, sorted));
		op_pb(a, b);
		a->pushed++;
		chunk_count++;
	}
	a->chunk++;
}

static int	find_max_pos(t_stack *b, t_stack *sorted)
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
		if (cur_idx)
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

static void	push_back_to_a(t_stack *a, t_stack *b, t_stack *sorted)
{
	int	pos;

	pos = find_max_pos(b, sorted);
	if (pos <= b->size / 2)
		while (pos-- > 0)
			op_rb(b);
	else
		while (pos++ < b->size)
			op_rrb(b);
	printf("remonte %d (index %d) dans A\n", b->top->value, get_indexed(b->top, sorted));
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
