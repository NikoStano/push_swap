/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:28:25 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/28 22:24:44 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bubble_sort(t_stack *st)
{
	int		i;
	int		j;
	int		tmp;
	t_list	*first;

	i = 0;
	first = st->top;
	while (i < st->size)
	{
		j = 0;
		st->top = first;
		while (j < st->size - i - 1)
		{
			if (st->top->value < st->top->next->value)
			{
				tmp = st->top->value;
				st->top->value = st->top->next->value;
				st->top->next->value = tmp;
			}
			j++;
			st->top = st->top->next;
		}
		i++;
	}
}

t_stack	*copy_stack(t_stack *a)
{
	t_stack	*st;

	st = malloc(sizeof(t_stack));
	if (!st)
		return (NULL);
	stack_init(st);
	if (copy_list(st, a))
		return (free(st), NULL);
	return (st);
}

void	add_stack(char **splited, t_stack *st)
{
	int		i;
	t_list	*new;
	long	value;

	value = 0;
	stack_init(st);
	i = 0;
	while (splited[i])
	{
		if (splited[i][0] == '\0')
			error_exit();
		if (!is_valid_int(splited[i], &value))
			error_exit();
		if (exist_in_stack(st, (int)value))
			error_exit();
		new = list_new((int)value);
		if (!new)
			error_exit();
		ft_lstadd_back(&st->top, new);
		st->size++;
		i++;
	}
}
