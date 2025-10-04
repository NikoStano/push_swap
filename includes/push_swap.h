/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:01:07 by nistanoj          #+#    #+#             */
/*   Updated: 2025/10/05 01:14:45 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
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
// static void	init_chunk(t_stack *a);
// static int	find_chunk_pos(t_stack *a, t_stack *sorted, int low, int high);
// static void	last_back(t_stack *a, t_stack *b, t_stack *sorted, int low);
// static void	push_chunks(t_stack *a, t_stack *b, t_stack *sorted);
int		sort_heavy(t_stack *a, t_stack *b);

/* sort_small.c 4 */
// static void	equal_to_three(t_stack *st);
// static void	sort_ff(t_stack *a, t_stack *b);
// static void	sort_four(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);

/* sort_utils.c 5 */
// static void	stack_init(t_stack *st);
void	rotate_up(t_stack *st, int size);
int		get_indexed(t_list *a, t_stack *sorted);
// static int	find_max_pos(t_stack *b, t_stack *sorted);
void	push_back_to_a(t_stack *a, t_stack *b, t_stack *sorted);

/* common.c 5 */
void	error_exit(void);
int		init_stacks(t_stack **a, t_stack **b);
void	clean_up(t_stack *a, t_stack *b, char **splited, int need_free);

/* list_utils.c 4 */
t_list	*list_new(int val);
void	list_delone(t_list *top);
void	list_clear(t_list **top);
int		copy_list(t_stack *dst, t_stack *src);
// void	print_stack(t_stack *st);

/* stack.c 4 */
void	stack_init(t_stack *st);
// static int	is_valid_int(char *s, int *value);
// static int	is_duplicate(t_stack *st, int value);
int		is_sorted(t_stack *st);
int		add_stack(char **av, t_stack *st);

/* utils.c 5 */
void	bubble_sort(t_stack *st);
t_stack	*copy_stack(t_stack *a);
t_stack	*sorted_stack(t_stack *a);
// static int	is_only_spaces(const char *str);
char	**split_args(int ac, char **av, int *need_free);

/* push_swap.c 4*/
// static void	choose_sort(t_stack *a, t_stack *b);

#endif
