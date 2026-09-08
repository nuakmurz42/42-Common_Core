/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:46:44 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/02/08 13:57:00 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	return (ft_recursive_factorial(nb - 1) * nb);
}
/*
#include <stdio.h>
int main(void)
{
        int nb = ft_recursive_factorial(4);
        printf("%d ", nb);
        return (0);
}*/
