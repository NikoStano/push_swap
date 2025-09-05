/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:03:08 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/05 15:09:21 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	stack_init(t_stack *st)
{
	st->top = NULL;
	st->size = 0;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 2)
		return (ft_printf("ERROR\n"), 0);
	a = malloc(sizeof * a);
	b = malloc(sizeof * b);
	if (!a || !b)
		error_exit();
	stack_init(a);
	stack_init(b);
	add_stack(argv, a);
	if ((a->size) - 1 <= 5)
		sort_small(a, b);
	else
		sort_heavy(a, b);
	return (free(a), free(b), 0);
}
