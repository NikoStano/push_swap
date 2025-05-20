/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:59:03 by nistanoj          #+#    #+#             */
/*   Updated: 2025/04/04 15:56:57 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_find_format(const char *format, va_list args, int *i)
{
	int	count;

	count = 0;
	if (format[*i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format[*i] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format[*i] == 'd' || format[*i] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format[*i] == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (format[*i] == 'x' || format[*i] == 'X')
		count += ft_puthex(va_arg(args, unsigned int), format[*i]);
	else if (format[*i] == 'p')
		count += ft_putptr(va_arg(args, unsigned long long));
	else if (format[*i] == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += ft_find_format(format, args, &i);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
