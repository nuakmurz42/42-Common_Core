/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:20:09 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/07/07 20:55:48 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_len(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (ft_putstr_len("(null)"));
	while (str[len])
	{
		ft_putchar_len(str[len]);
		len++;
	}
	return (len);
}
