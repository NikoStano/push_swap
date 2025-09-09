/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:01:07 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/09 17:02:06 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
	int		chunk_size;
	int		chunk;
	int		pushed;
	int		index;
}				t_stack;

/* op_...c */
void	op_pa(t_stack *a, t_stack *b);
void	op_pb(t_stack *a, t_stack *b);
void	op_ra(t_stack *a);
void	op_rb(t_stack *b);
void	op_rr(t_stack *a, t_stack *b);
void	op_rra(t_stack *a);
void	op_rrb(t_stack *b);
void	op_rrr(t_stack *a, t_stack *b);
void	op_sa(t_stack *a);
void	op_sb(t_stack *b);
void	op_ss(t_stack *a, t_stack *b);

/* op_stack.c */
void	stack_push(t_stack *st, int value);
int		stack_pop(t_stack *st);
void	stack_rotate(t_stack *st);
void	stack_reverse_rotate(t_stack *st);
void	stack_swap(t_stack *st);

/* sort_heavy.c */
int		sort_heavy(t_stack *a, t_stack *b);

/* sort_small.c */
void	sort_small(t_stack *a, t_stack *b);

/* sort_utils.c */
void	rotate_up(t_stack *st, int size);
void	push_to_b(t_stack *a, t_stack *b);
void	push_back_to_a(t_stack *a, t_stack *b, t_stack *sorted);

/* list_index.c */
int		get_indexed(t_node *a, t_stack *sorted);

/* list_utils.c */
t_node	*list_new(int val);
t_node	*listlast(t_node *top);
void	list_add_back(t_node **top, t_node *new);
void	list_delone(t_node *top);
void	list_clear(t_node **top);

/* stack.c */
void	stack_init(t_stack *st);
t_stack	*copy_stack(t_stack *a);
void	add_stack(char **av, t_stack *st);

/* utils.c */
void	error_exit(void);
int		copy_list(t_stack *dst, t_stack *src);

// void	print_stack(t_stack *st);
// int		index_list_a(t_stack *a);
// void	init_chunk(t_stack *a);
// void	equal_to_three(t_stack *st);
// void	less_or_five(t_stack *a, t_stack *b);
// int		get_size(char **av);
// void	bubble_sort(t_stack *sorted);
// int		find_chunk_pos(t_stack *a, t_stack *sorted, int low, int high);
// int		find_max_pos(t_stack *b, t_stack *sorted);

#endif
