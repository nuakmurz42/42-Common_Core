/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 22:05:36 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/07/07 00:00:47 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_len(unsigned int n, char x)
{
	char	*base;
	int		len;

	len = 0;
	if (x == 'X')
		base = "0123456789ABCDEF";
	else if (x == 'x')
		base = "0123456789abcdef";
	if (n > 15)
	{
		len += ft_puthex_len(n / 16, x);
		len += ft_putchar_len(base[n % 16]);
	}
	else
		len += ft_putchar_len(base[n]);
	return (len);
}
