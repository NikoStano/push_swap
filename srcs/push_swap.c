/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:03:08 by nistanoj          #+#    #+#             */
/*   Updated: 2025/10/05 01:01:18 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	choose_sort(t_stack *a, t_stack *b)
{
	stack_init(b);
	if (a->size <= 5)
		sort_small(a, b);
	else
		if (sort_heavy(a, b))
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
		return (1);
	if (init_stacks(&a, &b))
	{
		if (need_free)
			ft_free_sp(splited);
		return (1);
	}
	if (add_stack(splited, a))
		return (clean_up(a, b, splited, need_free), 1);
	if (!is_sorted(a))
		choose_sort(a, b);
	clean_up(a, b, splited, need_free);
	return (0);
}
