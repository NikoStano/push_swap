/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 00:15:20 by nistanoj          #+#    #+#             */
/*   Updated: 2025/10/05 01:11:46 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	clean_up_args(char **splited, int need_free)
{
	if (need_free && splited)
		ft_free_sp(splited);
}

static int	execute_instruction(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		return (stack_swap(a), 1);
	else if (!ft_strncmp(line, "sb\n", 3))
		return (stack_swap(b), 1);
	else if (!ft_strncmp(line, "ss\n", 3))
		return (stack_swap(a), stack_swap(b), 1);
	else if (!ft_strncmp(line, "pa\n", 3))
		return (stack_push(a, stack_pop(b)), 1);
	else if (!ft_strncmp(line, "pb\n", 3))
		return (stack_push(b, stack_pop(a)), 1);
	else if (!ft_strncmp(line, "ra\n", 3))
		return (stack_rotate(a), 1);
	else if (!ft_strncmp(line, "rb\n", 3))
		return (stack_rotate(b), 1);
	else if (!ft_strncmp(line, "rr\n", 3))
		return (stack_rotate(a), stack_rotate(b), 1);
	else if (!ft_strncmp(line, "rra\n", 4))
		return (stack_reverse_rotate(a), 1);
	else if (!ft_strncmp(line, "rrb\n", 4))
		return (stack_reverse_rotate(b), 1);
	else if (!ft_strncmp(line, "rrr\n", 4))
		return (stack_reverse_rotate(a), stack_reverse_rotate(b), 1);
	else
		return (0);
}

static int	read_and_execute(t_stack *a, t_stack *b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!execute_instruction(line, a, b))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}

static int	check_sorted(t_stack *a, t_stack *b)
{
	if (b->size != 0)
		return (0);
	return (is_sorted(a));
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**splited;
	int		need_free;
	int		result;

	if (ac < 2)
		return (0);
	need_free = 0;
	splited = split_args(ac, av, &need_free);
	if (!splited)
		return (1);
	if (init_stacks(&a, &b))
		return (clean_up_args(splited, need_free), 1);
	if (add_stack(splited, a))
		return (clean_up(a, b, splited, need_free), 1);
	result = read_and_execute(a, b);
	if (!result)
		write(2, "Error\n", 6);
	else if (check_sorted(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clean_up(a, b, splited, need_free);
	return (!result);
}
