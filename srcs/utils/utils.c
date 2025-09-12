/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 08:05:34 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/12 17:22:02 by nistanoj         ###   ########.fr       */
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
	int	value;
	t_stack *sorted;

	sorted = copy_stack(st);
	if (!sorted)
		error_exit();
	value = sorted->top->value;
	while (sorted->top)
	{

		if (value > sorted->top->value)
		{
			list_clear(&sorted->top);
			return (free(sorted), 1);
		}
		value = sorted->top->value;
		sorted->top = sorted->top->next;
	}
	list_clear(&sorted->top);
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

static int	ft_isadigit(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

long	atol_ps(const char *nptr)
{
	int			neg;
	long long	nb;

	neg = 1;
	nb = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	if (!ft_isadigit(nptr))
		error_exit();
	while (ft_isdigit(*nptr))
	{
		nb = nb * 10 + *nptr - '0';
		if (nb * neg > INT_MAX)
			return ((long)INT_MAX + 1);
		if (nb * neg < INT_MIN)
			return ((long)INT_MIN - 1);
		nptr++;
	}
	return (nb * neg);
}
