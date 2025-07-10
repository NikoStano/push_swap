/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:03:08 by nistanoj          #+#    #+#             */
/*   Updated: 2025/07/09 13:36:53 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int	main(int ac, char **av)
// {
// 	int	i;

// 	i = 1;
// 	if (ac < 2)
// 		return (ft_printf("%s\n", "Erreur ARGS !"));
// 	else
// 	{
// 		while (av[i])
// 			ft_printf("%s\n", av[i++]);
// 	}
// }
static void	init_chunks(int n, int *chunk_count, int **pivots)
{
	*chunk_count = n / 10;
	if (n % 10 != 0)
		*chunk_count += 1;
	*pivots = malloc(sizeof(int) * (*chunk_count));
	if (!*pivots)
		error_exit();
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*sorted;
	int		*pivots;
	int		chunk_count;

	if (argc < 2)
		return (0);
	a = malloc(sizeof * a);
	b = malloc(sizeof * b);
	if (!a || !b)
		error_exit();
	parse_args(a, argv + 1, argc - 1);
	printf("%d\n", a->top->value);
	stack_init(b);
	if (a->size <= 10)
	{
		sort_small(a);
		return (free(a), free(b), 0);
	}
	sorted = get_sorted_array(a);
	init_chunks(a->size, &chunk_count, &pivots);
	compute_pivots(sorted, a->size, pivots, chunk_count);
	while (chunk_count--)
		push_chunk_to_b(a, b, pivots[chunk_count]);
	push_back_to_a(a, b);
	return (free(pivots), free(sorted), free(a), free(b), 0);
}
