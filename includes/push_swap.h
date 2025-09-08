/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:01:07 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/08 08:26:39 by nistanoj         ###   ########.fr       */
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
}				t_stack;

/* push_swap.c */
void	stack_init(t_stack *st);
void	error_exit(void);

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

/* sort_small.c */
void	rotate_up(t_stack *st, int size);
void	equal_to_three(t_stack *st);
void	push_to_b(t_stack *a, t_stack *b);
void	less_or_five(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);

/* sort_heavy.c */
int		sort_heavy(t_stack *a, t_stack *b);

/* init_stack.c */
int		get_size(char **av);
void	add_stack(char **av, t_stack *st);

/* list_index.c */
int		copy_array(t_stack *dst, t_stack *src);
void	bubble_sort(t_stack *sorted);
int		get_indexed(t_node *a, t_stack *sorted);
int		index_list_a(t_stack *a);

/* list_utils.c */
t_node	*list_new(int val);
t_node	*listlast(t_node *top);
void	list_add_back(t_node **top, t_node *new);
void	list_delone(t_node *top);
void	list_clear(t_node **top);

/* utils.c */
t_stack	*create_stack(t_stack *a);
void	init_chunk(t_stack *a);
void	print_stack(t_stack *st);

#endif
