/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 08:05:34 by nistanoj          #+#    #+#             */
/*   Updated: 2025/10/04 20:04:59 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

static int	ft_is_valid_char(char c, int i)
{
	if (i && (c == '-' || c == '+'))
		return (1);
	return (c >= '0' && c <= '9');
}

int	ft_is_int(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (!str[i][j])
			return (0);
		while (str[i][j])
		{
			if (!ft_is_valid_char(str[i][j], j == 0))
				return (0);
			j++;
		}
		if (j == 1 && (str[i][0] == '-' || str[i][0] == '+'))
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
		if (!av[1] || !av[1][0])
			return (NULL);
		split = ft_split(av[1], ' ');
		if (!split)
			return (write(2, "Error\n", 6), NULL);
		if (!split[0])
			return (ft_free_sp(split), NULL);
		*need_free = 1;
		return (split);
	}
	return (av + 1);
}

int	is_valid_int(const char *s, int *value)
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
	*value = v;
	return (1);
}
