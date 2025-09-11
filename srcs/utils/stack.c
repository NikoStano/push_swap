/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:28:25 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/11 21:33:59 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_init(t_stack *st)
{
	st->top = NULL;
	st->size = 0;
	st->chunk_size = 0;
	st->chunk = 0;
	st->pushed = 0;
}

static void	bubble_sort(t_stack *sorted)
{
	int		i;
	int		j;
	int		tmp;
	t_list	*first;

	i = 0;
	first = sorted->top;
	while (i < sorted->size)
	{
		j = 0;
		sorted->top = first;
		while (j < sorted->size - i - 1)
		{
			if (sorted->top->value < sorted->top->next->value)
			{
				tmp = sorted->top->value;
				sorted->top->value = sorted->top->next->value;
				sorted->top->next->value = tmp;
			}
			j++;
			sorted->top = sorted->top->next;
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
	bubble_sort(st);
	return (st);
}

static int	get_size(char **av)
{
	int	i;

	i = 1;
	while (av[i])
		i++;
	return (i);
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

void	add_stack(char **av, t_stack *st)
{
	int		i;
	t_list	*new;
	long	value;

	value = 0;
	st->size = (get_size(av) - 1);
	i = 0;
	while (i < st->size)
	{
		if (av[i] && av[i + 1])
		{
			value = ft_atol(av[i + 1]);
			if (value > INT_MAX || value < INT_MIN)
				error_exit();
			if (exist_in_stack(st, (int)value))
				error_exit();
			new = list_new((int)value);
			if (!new)
				error_exit();
			ft_lstadd_back(&st->top, new);
		}
		i++;
	}
}
