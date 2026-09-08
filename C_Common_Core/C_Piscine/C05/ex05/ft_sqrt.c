/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:58:14 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/02/10 16:59:34 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
	printf("9 = %d ", ft_sqrt(9));
	printf("0 = %d ", ft_sqrt(0));
	printf("81 = %d ", ft_sqrt(81));
	printf("16 = %d ", ft_sqrt(16));
	printf("1 = %d ", ft_sqrt(1));
	return (0);
}
*/
