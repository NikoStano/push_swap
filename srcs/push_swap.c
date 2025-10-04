/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:03:08 by nistanoj          #+#    #+#             */
/*   Updated: 2025/10/04 23:12:09 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	choose_sort(t_stack *a, t_stack *b)
{
	stack_init(b);
	if (a->size <= 5)
		sort_small(a, b);
	else
		if (sort_heavy(a, b))
			error_exit();
}

static void	clenup_up(t_stack *a, t_stack *b, char **splited, int need_free)
{
	if (a)
	{
		list_clear(&a->top);
		free(a);
	}
	if (b)
		free(b);
	if (need_free && splited)
		ft_free_sp(splited);
}

static int	init_stacks(t_stack **a, t_stack **b, char **splited)
{
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	if (!*a || !*b)
	{
		if (*a)
			free(*a);
		if (*b)
			free(*b);
		return (1);
	}
	if (add_stack(splited, *a))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**splited;
	int		need_free;

	if (ac < 2)
		return (0);
	need_free = 0;
	splited = split_args(ac, av, &need_free);
	if (!splited)
		return (1);
	if (init_stacks(&a, &b, splited))
	{
		if (need_free)
			ft_free_sp(splited);
		return (1);
	}
	if (!is_sorted(a))
		choose_sort(a, b);
	clenup_up(a, b, splited, need_free);
	return (0);
}
