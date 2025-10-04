/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:28:25 by nistanoj          #+#    #+#             */
/*   Updated: 2025/10/04 20:04:41 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

static int	exist_in_stack(t_stack *st, int value)
{
	t_list	*tmp;

	tmp = st->top;
	while (tmp)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_valid_check(char **splited, int i, t_stack *st, int *value)
{
	if (splited[i][0] == '\0')
	{
		ft_free_sp(splited);
		return (0);
	}
	if (!is_valid_int(splited[i], value))
		return (0);
	if (exist_in_stack(st, *value))
		return (0);
	return (1);
}

int	add_stack(char **splited, t_stack *st)
{
	int		i;
	t_list	*new;
	int		value;

	value = 0;
	stack_init(st);
	i = -1;
	while (splited[++i])
	{
		if (!ft_valid_check(splited, i, st, &value))
			return (write(2, "Error\n", 6), 1);
		new = list_new(value);
		if (!new)
			error_exit();
		ft_lstadd_back(&st->top, new);
		st->size++;
	}
	return (0);
}
