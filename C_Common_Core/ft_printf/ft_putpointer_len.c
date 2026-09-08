/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 22:59:13 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/07/07 22:15:26 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer_len(unsigned long n)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (n > 15)
	{
		len = ft_putpointer_len(n / 16);
		len += ft_putchar_len(base[n % 16]);
	}
	else
	{
		len += ft_putchar_len(base[n]);
	}
	return (len);
}
