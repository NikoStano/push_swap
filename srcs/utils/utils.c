/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 08:05:34 by nistanoj          #+#    #+#             */
/*   Updated: 2025/10/04 21:09:13 by nistanoj         ###   ########.fr       */
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

t_stack	*sorted_stack(t_stack *a)
{
	t_stack	*sorted;

	sorted = copy_stack(a);
	if (!sorted)
		return (NULL);
	bubble_sort(sorted);
	return (sorted);
}

static int	is_only_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

char	**split_args(int ac, char **av, int *need_free)
{
	char	**split;

	*need_free = 0;
	if (ac == 2)
	{
		if (!av[1] || !av[1][0] || is_only_spaces(av[1]))
		{
			write(2, "Error\n", 6);
			return (NULL);
		}
		split = ft_split(av[1], ' ');
		if (!split || !split[0])
		{
			if (split)
				ft_free_sp(split);
			write(2, "Error\n", 6);
			return (NULL);
		}
		*need_free = 1;
		return (split);
	}
	return (av + 1);
}
