/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:50:04 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/06/27 21:45:35 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*a;
	unsigned char		*b;

	a = (const unsigned char *)src;
	b = (unsigned char *) dest;
	if (b > a)
	{
		i = n;
		while (i > 0)
		{
			i--;
			b[i] = a[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			b[i] = a[i];
			i++;
		}
	}
	return (dest);
}
