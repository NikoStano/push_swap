/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:03:08 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/05 18:51:37 by nistanoj         ###   ########.fr       */
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
		error_exit();
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		error_exit();
	stack_init(a);
	stack_init(b);
	add_stack(argv, a);
	if (a->size <= 5)
		sort_small(a, b);
	else
		if (sort_heavy(a, b))
			error_exit();
	list_clear(&a->top);
	a->size = 0;
	return (free(a), free(b), 0);
}
