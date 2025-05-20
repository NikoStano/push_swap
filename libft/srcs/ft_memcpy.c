/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:41:19 by nistanoj          #+#    #+#             */
/*   Updated: 2025/03/16 13:50:46 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*srrc;

	dst = (unsigned char *)dest;
	srrc = (unsigned char *)src;
	if (!dst && !srrc)
		return (NULL);
	while (n--)
	{
		*dst = *srrc;
		dst++;
		srrc++;
	}
	return (dest);
}
