/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 20:09:36 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/06/27 22:25:50 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_length(long n)
{
	long	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	len;
	long	m;
	char	*result;

	m = n;
	len = ft_length(m);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (m == 0)
		result[0] = '0';
	if (m < 0)
	{
		result[0] = '-';
		m = -m;
	}
	while (m > 0)
	{
		len--;
		result[len] = (m % 10) + '0';
		m /= 10;
	}
	return (result);
}
