/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:03:08 by nistanoj          #+#    #+#             */
/*   Updated: 2025/10/04 22:17:54 by nistanoj         ###   ########.fr       */
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

static void	ft_check_stack(t_stack *a, t_stack *b)
{
	if (b)
		free(b);
	if (a)
		free(a);
	error_exit();
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
		return (0);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		ft_check_stack(a, b);
	if (add_stack(splited, a))
	{
		if (need_free)
			ft_free_sp(splited);
		return (free(a), free(b), 1);
	}
	if (!is_sorted(a))
		choose_sort(a, b);
	list_clear(&a->top);
	if (need_free)
		ft_free_sp(splited);
	return (free(a), free(b), 0);
}
