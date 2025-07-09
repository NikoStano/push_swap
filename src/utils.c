/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 07:57:06 by nistanoj          #+#    #+#             */
/*   Updated: 2025/07/09 08:18:18 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

// static long	ft_atoi_long(const char *s)
// {
// 	long	result;
// 	int		sign;

// 	result = 0;
// 	sign = 1;
// 	while (*s == ' ' || (*s >= '	' && *s <= ' '))
// 		s++;
// 	if (*s == '+' || *s == '-')
// 	{
// 		if (*s == '-')
// 			sign = -1;
// 		s++;
// 	}
// 	while (*s >= '0' && *s <= '9')
// 	{
// 		result = result * 10 + (*s - '0');
// 		s++;
// 		if (result * sign < INT_MIN || result * sign > INT_MAX)
// 			error_exit();
// 	}
// 	return (result * sign);
// }

void	parse_args(t_stack *a, char **vals, int n)
{
	int		i;
	char	*endptr;
	long	num;

	stack_init(a);
	i = 0;
	while (i < n)
	{
		num = strtol(vals[i], &endptr, 10);
		if (*endptr != '\0'
			|| num < INT_MIN
			|| num > INT_MAX)
			error_exit();
		stack_push(a, (int)num);
		i++;
	}
}

static int	cmp_int(const void *p1, const void *p2)
{
	return (*(int *)p1 - *(int *)p2);
}

int	*get_sorted_array(t_stack *st)
{
	int		*i_arr;
	int		i;
	t_node	*cur;

	if (!st->size)
		error_exit();
	i_arr = malloc(sizeof(int) * st->size);
	if (!i_arr)
		error_exit();
	cur = st->top;
	i = 0;
	while (cur)
	{
		i_arr[i++] = cur->value;
		cur = cur->next;
	}
	qsort(i_arr, st->size, sizeof(int), cmp_int);
	return (i_arr);
}

void	compute_pivots(int *arr, int n, int *pivots, int chunks)
{
	int	i;
	int	step;

	step = n / chunks;
	i = 0;
	while (i < chunks)
	{
		if (i == chunks - 1)
			pivots[i] = arr[n - 1];
		else
			pivots[i] = arr[(i + 1) * step - 1];
		i++;
	}
}
