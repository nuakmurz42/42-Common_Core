/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:00:08 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/02/09 18:28:56 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str);
int		ft_base_checker(char *base);
void	ft_recursive(long nb, char *base, int base_len);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	nb;

	nb = nbr;
	base_len = ft_strlen(base);
	if (base_len <= 1)
		return ;
	if (ft_base_checker(base))
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	ft_recursive(nb, base, base_len);
}

void	ft_recursive(long nb, char *base, int base_len)
{
	char	c;

	if (nb >= base_len)
		ft_recursive(nb / base_len, base, base_len);
	c = base[nb % base_len];
	write(1, &c, 1);
}

int	ft_base_checker(char *base )
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (base[i])
	{
		j = i +1;
		c = base[i];
		if (base[i] == '+' || base[i] == '-')
			return (1);
		while (base[j])
		{
			if (c == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
