/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:38:22 by nistanoj          #+#    #+#             */
/*   Updated: 2025/09/15 19:40:01 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	**split_args(int ac, char **av, int *need_free)
{
	char	**split;

	*need_free = 0;
	if (ac < 2)
		return (NULL);
	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		if (!split || !split[0])
		{
			ft_free_split(split);
			return (NULL);
		}
		*need_free = 1;
		return (split);
	}
	return (av + 1);
}

int	is_valid_int(const char *s, long *out)
{
	char	*end;
	long	v;

	if (!s || !*s)
		return (0);
	v = strtol(s, &end, 10);
	if (*end != '\0')
		return (0);
	if (v < INT_MIN || v > INT_MAX)
		return (0);
	*out = v;
	return (1);
}
