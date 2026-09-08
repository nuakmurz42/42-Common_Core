/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:12:18 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/01/26 20:48:10 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

#include <stdio.h>

int main ()
{
	int a = 10;
	int b = 20;
	printf("a = %d,   b = %d", a, b);
	ft_swap(&a, &b);
	printf("\n");
	printf("a = %d,   b = %d", a, b);


}
