/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 21:37:12 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/07/07 00:04:10 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
	{
		len += ft_putunsigned_len(n / 10);
		len += ft_putchar_len((n % 10) + '0');
	}
	else
	{
		len += ft_putchar_len((n % 10) + '0');
	}
	return (len);
}
