/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 21:30:21 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/01/26 17:25:18 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_helper(char *arr, int size, int index, char digit)
{
	if (index == size)
	{
		write(1, arr, size);
		if (arr[0] - '0' < (10 - size))
			write(1, ", ", 2);
	}
	else
	{
		while (digit - '0' <= (10 - size) + index)
		{
			arr[index] = digit;
			ft_print_helper(arr, size, index + 1, digit + 1);
			digit++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	arr[9];

	if (n > 0 && n < 10)
	{
		ft_print_helper(arr, n, 0, '0');
	}
}
