/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:01:07 by nistanoj          #+#    #+#             */
/*   Updated: 2025/07/09 08:02:01 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}				t_stack;

/* error handling */
void	error_exit(void);

/* parsing */
void	parse_args(t_stack *a, char **vals, int n);

/* utils */
void	stack_init(t_stack *st);
void	stack_push(t_stack *st, int value);
int		stack_pop(t_stack *st);
void	stack_rotate(t_stack *st);
void	stack_reverse_rotate(t_stack *st);
void	stack_swap(t_stack *st);

/* sorting small stacks */
void	sort_small(t_stack *a);

/* pivots & chunks */
int		*get_sorted_array(t_stack *st);
void	compute_pivots(int *arr, int n, int *pivots, int chunks);
void	push_chunk_to_b(t_stack *a, t_stack *b, int pivot);
void	push_back_to_a(t_stack *a, t_stack *b);

/* operations */
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

#endif
