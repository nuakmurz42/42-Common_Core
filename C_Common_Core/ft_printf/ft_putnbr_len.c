/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:54:16 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/07/07 00:07:38 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_len(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putnbr_len(n / 10);
		len += ft_putchar_len('8');
		return (len);
	}
	if (n < 0)
	{
		len += ft_putchar_len('-');
		n = -n;
	}
	if (n > 9)
	{
		len += ft_putnbr_len(n / 10);
		len += ft_putchar_len((n % 10) + '0');
	}
	else
	{
		len += ft_putchar_len((n % 10) + '0');
	}
	return (len);
}
