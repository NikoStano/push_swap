/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:01:07 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/29 01:15:03 by nistanoj         ###   ########.fr       */
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

typedef struct s_stack
{
	t_list	*top;
	int		size;
	int		chunk_size;
	int		chunk;
	int		pushed;
	int		index;
}				t_stack;

/* op_one.c 4 */
void	op_pa(t_stack *a, t_stack *b);
void	op_pb(t_stack *a, t_stack *b);
void	op_sa(t_stack *a);
void	op_sb(t_stack *b);

/* op_stack.c 5 */
void	stack_push(t_stack *st, int value);
int		stack_pop(t_stack *st);
void	stack_rotate(t_stack *st);
void	stack_reverse_rotate(t_stack *st);
void	stack_swap(t_stack *st);

/* op_three.c 3 */
void	op_ss(t_stack *a, t_stack *b);
void	op_rr(t_stack *a, t_stack *b);
void	op_rrr(t_stack *a, t_stack *b);

/* op_two.c 4 */
void	op_ra(t_stack *a);
void	op_rb(t_stack *b);
void	op_rra(t_stack *a);
void	op_rrb(t_stack *b);

/* sort_heavy.c 5 */
int		sort_heavy(t_stack *a, t_stack *b);

/* sort_small.c 4 */
void	sort_small(t_stack *a, t_stack *b);

/* sort_utils.c 4 */
void	rotate_up(t_stack *st, int size);
int		get_indexed(t_list *a, t_stack *sorted);
void	push_back_to_a(t_stack *a, t_stack *b, t_stack *sorted);

/* list_utils.c 4 */
t_list	*list_new(int val);
void	list_delone(t_list *top);
void	list_clear(t_list **top);
int		copy_list(t_stack *dst, t_stack *src);
// void	print_stack(t_stack *st);

/* stack.c 3 */
void	bubble_sort(t_stack *st);
t_stack	*copy_stack(t_stack *a);
void	add_stack(char **av, t_stack *st);

/* utils.c 5 */
void	error_exit(void);
int		check_sort_list(t_stack *st);
int		exist_in_stack(t_stack *st, int value);
char	**split_args(int ac, char **av, int *need_free);
int		is_valid_int(const char *s, long *out);

void	stack_init(t_stack *st);

#endif
