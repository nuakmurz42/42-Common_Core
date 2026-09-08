/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:21:49 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/01/26 17:27:08 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char x, char y)
{
	char	div;
	char	mod;

	div = '0' + (x / 10);
	mod = '0' + (x % 10);
	write(1, &div, 1);
	write(1, &mod, 1);
	write(1, " ", 1);
	div = '0' + (y / 10);
	mod = '0' + (y % 10);
	write(1, &div, 1);
	write(1, &mod, 1);
	if (x < 98)
		write (1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 0;
	while (x <= 98)
	{
		y = x + 1;
		while (y <= 99)
		{
			ft_print(x, y);
			y++;
		}
		x++;
	}
}
