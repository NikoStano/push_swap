/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 08:05:34 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/29 01:14:10 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	check_sort_list(t_stack *st)
{
	int		value;
	t_stack	*sorted;
	t_list	*first;

	sorted = copy_stack(st);
	if (!sorted)
		error_exit();
	value = sorted->top->value;
	first = sorted->top;
	while (sorted->top)
	{
		if (value > sorted->top->value)
		{
			list_clear(&first);
			return (free(sorted), 1);
		}
		value = sorted->top->value;
		sorted->top = sorted->top->next;
	}
	list_clear(&first);
	return (free(sorted), 0);
}

int	exist_in_stack(t_stack *st, int value)
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

char	**split_args(int ac, char **av, int *need_free)
{
	char	**split;

	*need_free = 0;
	if (ac < 2)
		return (NULL);
	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		if (!split || !split[0])
		{
			ft_free_split(split);
			return (NULL);
		}
		*need_free = 1;
		return (split);
	}
	return (av + 1);
}

int	is_valid_int(const char *s, long *out)
{
	char	*end;
	long	v;

	if (!s || !*s)
		return (0);
	v = ft_strtol(s, &end, 10);
	if (*end != '\0')
		return (0);
	if (v < INT_MIN || v > INT_MAX)
		return (0);
	*out = v;
	return (1);
}
