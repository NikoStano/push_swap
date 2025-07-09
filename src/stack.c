/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 08:04:41 by nistanoj          #+#    #+#             */
/*   Updated: 2025/07/09 08:18:11 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_init(t_stack *st)
{
	st->top = NULL;
	st->size = 0;
}

void	stack_push(t_stack *st, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		error_exit();
	node->value = value;
	node->next = st->top;
	st->top = node;
	st->size++;
}

int	stack_pop(t_stack *st)
{
	t_node	*tmp;
	int		val;

	if (st->size == 0)
		error_exit();
	tmp = st->top;
	val = tmp->value;
	st->top = tmp->next;
	free(tmp);
	st->size--;
	return (val);
}

void	stack_rotate(t_stack *st)
{
	t_node	*first;
	t_node	*last;

	if (st->size < 2)
		return ;
	first = st->top;
	st->top = first->next;
	first->next = NULL;
	last = st->top;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	stack_reverse_rotate(t_stack *st)
{
	t_node	*prev;
	t_node	*cur;

	if (st->size < 2)
		return ;
	prev = st->top;
	while (prev->next->next)
		prev = prev->next;
	cur = prev->next;
	prev->next = NULL;
	cur->next = st->top;
	st->top = cur;
}

void	stack_swap(t_stack *st)
{
	t_node	*first;
	t_node	*second;

	if (st->size < 2)
		return ;
	first = st->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	st->top = second;
}
