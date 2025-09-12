/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:41:20 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/12 17:11:41 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*list_new(int val)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = val;
	new->next = NULL;
	return (new);
}

void	list_delone(t_list *top)
{
	if (!top)
		return ;
	free(top);
}

void	list_clear(t_list **top)
{
	t_list	*tmp;

	if (!top || !*top)
		return ;
	while (*top)
	{
		tmp = (*top)->next;
		list_delone(*top);
		*top = tmp;
	}
	*top = NULL;
}

int	copy_list(t_stack *dst, t_stack *src)
{
	t_list	*n_lst;
	t_list	*curr;

	curr = src->top;
	dst->size = 0;
	while (curr)
	{
		n_lst = list_new(curr->value);
		if (!n_lst)
			return (list_clear(&dst->top), 1);
		ft_lstadd_back(&dst->top, n_lst);
		dst->size++;
		curr = curr->next;
	}
	return (0);
}

// void	print_stack(t_stack *st)
// {
// 	t_list	*cur;

// 	cur = st->top;
// 	ft_printf("Stack : ");
// 	while (cur)
// 	{
// 		ft_printf("%d ", cur->value);
// 		cur = cur->next;
// 	}
// 	ft_printf("\n");
// }
