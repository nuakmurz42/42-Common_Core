/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:35:34 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/01/25 14:07:07 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	a_temp;
	int	b_temp;

	a_temp = *a / *b;
	b_temp = *a % *b;
	*a = a_temp;
	*b = b_temp;
}
