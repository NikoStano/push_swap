/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:28:25 by nistanoj          #+#    #+#             */
/*   Updated: 2025/10/04 20:31:33 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_valid_int(const char *s, int *value)
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

static int	is_duplicate(t_stack *st, int value)
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

int	is_sorted(t_stack *st)
{
	t_list	*curr;

	if (!st || !st->top)
		return (1);
	curr = st->top;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
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
		if (!is_valid_int(splited[i], &value) || is_duplicate(st, value))
			return (write(2, "Error\n", 6), 1);
		new = list_new(value);
		if (!new)
			error_exit();
		ft_lstadd_back(&st->top, new);
		st->size++;
	}
	return (0);
}
