/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:03:08 by nistanoj          #+#    #+#             */
/*   Updated: 2025/05/20 22:54:33 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
		return (ft_printf("%s\n", "Erreur ARGS !"));
	else
	{
		while (av[i])
			ft_printf("%s\n", av[i++]);
	}
}
