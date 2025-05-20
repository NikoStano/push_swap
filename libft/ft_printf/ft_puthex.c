/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:28:12 by nistanoj          #+#    #+#             */
/*   Updated: 2025/04/04 15:30:13 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	ft_puthex_helper(unsigned int n, char format)
{
	if (n >= 16)
	{
		ft_puthex_helper(n / 16, format);
		ft_puthex_helper(n % 16, format);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
		{
			if (format == 'x')
				ft_putchar(n - 10 + 'a');
			else
				ft_putchar(n - 10 + 'A');
		}
	}
}

int	ft_puthex(unsigned int n, char format)
{
	int	count;

	count = ft_hex_len(n);
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	ft_puthex_helper(n, format);
	return (count);
}
