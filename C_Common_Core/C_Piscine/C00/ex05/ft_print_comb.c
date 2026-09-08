/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:30:37 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/01/26 12:50:21 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char c, char j, char s)
{
	write(1, &c, 1);
	write(1, &j, 1);
	write(1, &s, 1);
	if (!(c == '7' && j == '8' && s == '9'))
	{
		write (1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	c;
	char	j;
	char	s;

	c = '0';
	while (c <= '7')
	{
		j = c + 1;
		while (j <= '8')
		{
			s = j + 1;
			while (s <= '9')
			{
				ft_print(c, j, s);
				s++;
			}
			j++;
		}
		c++;
	}
}
