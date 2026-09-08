/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:00:47 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/01/26 20:44:39 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

#include <stdio.h>

int main ()
{
	int a = 21;
	int *p = &a;
	int **pp = &p;
	int ***ppp = &pp;
	int ****pppp = &ppp;
	int *****ppppp = &pppp;
	int ******pppppp = &ppppp;
	int *******ppppppp = &pppppp;
	int ********pppppppp = &ppppppp;

	ft_ultimate_ft(&pppppppp);

	printf ("%d", a);
	return (0);
}
