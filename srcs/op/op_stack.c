/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 02:18:16 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/10 20:05:16 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_push(t_stack *st, int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		error_exit();
	node->value = value;
	node->next = st->top;
	st->top = node;
	st->size++;
}

int	stack_pop(t_stack *st)
{
	t_list	*tmp;
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
	t_list	*frst;
	t_list	*last;

	if (st->size < 2)
		return ;
	frst = st->top;
	st->top = frst->next;
	frst->next = NULL;
	last = st->top;
	while (last->next)
		last = last->next;
	last->next = frst;
}

void	stack_reverse_rotate(t_stack *st)
{
	t_list	*prev;
	t_list	*curr;

	if (st->size < 2)
		return ;
	prev = st->top;
	while (prev->next->next)
		prev = prev->next;
	curr = prev->next;
	prev->next = NULL;
	curr->next = st->top;
	st->top = curr;
}

void	stack_swap(t_stack *st)
{
	t_list	*a;
	t_list	*b;

	if (st->size < 2)
		return ;
	a = st->top;
	b = a->next;
	a->next = b->next;
	b->next = a;
	st->top = b;
}
