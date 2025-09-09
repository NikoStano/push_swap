/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 08:05:34 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/09 17:01:46 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	copy_list(t_stack *dst, t_stack *src)
{
	t_node	*n_lst;
	t_node	*curr;

	curr = src->top;
	dst->size = 0;
	while (curr)
	{
		n_lst = list_new(curr->value);
		if (!n_lst)
			return (list_clear(&dst->top), 1);
		list_add_back(&dst->top, n_lst);
		dst->size++;
		curr = curr->next;
	}
	return (0);
}

// void	print_stack(t_stack *st)
// {
// 	t_node	*cur;

// 	cur = st->top;
// 	ft_printf("Stack : ");
// 	while (cur)
// 	{
// 		ft_printf("%d ", cur->value);
// 		cur = cur->next;
// 	}
// 	ft_printf("\n");
// }
