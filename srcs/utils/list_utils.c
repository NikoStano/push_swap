/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:41:20 by nistanoj          #+#    #+#             */
/*   Updated: 2025/10/05 19:04:41 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_del(void *content)
{
	(void)content;
}

int	copy_list(t_stack *dst, t_stack *src)
{
	t_list	*n_lst;
	t_list	*curr;

	curr = src->top;
	dst->size = 0;
	while (curr)
	{
		n_lst = ft_lstnew((void *)(long)curr->value);
		if (!n_lst)
			return (ft_lstclear(&dst->top, ft_del), 1);
		ft_lstadd_back(&dst->top, n_lst);
		curr = curr->next;
	}
	dst->size = ft_lstsize(dst->top);
	return (0);
}

// t_list	*list_new(int val)
// {
// 	t_list	*new;

// 	new = malloc(sizeof(t_list));
// 	if (!new)
// 		return (NULL);
// 	new->value = val;
// 	new->next = NULL;
// 	return (new);
// }

// void	list_delone(t_list *top)
// {
// 	if (!top)
// 		return ;
// 	free(top);
// }

// void	list_clear(t_list **top)
// {
// 	t_list	*tmp;

// 	if (!top || !*top)
// 		return ;
// 	while (*top)
// 	{
// 		tmp = (*top)->next;
// 		ft_lstdelone(*top, ft_del());
// 		*top = tmp;
// 	}
// 	*top = NULL;
// }

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
