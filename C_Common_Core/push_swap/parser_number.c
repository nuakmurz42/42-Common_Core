/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 21:42:51 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/07/28 21:43:25 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(char c)
{
        if (c >= '0' && c <= '9')
                return (1);
        return (0);
}
int	ft_int_size_check(int sign, long nmb, int digit)
{
	long	limit;

	limit = INT_MAX;
	if (sign == -1)
		limit = 2147483648L;
	if (nmb > limit / 10)
		return (0);
	if (nmb == limit / 10 && digit > limit % 10)
		return (0);
	return (1);
}

int     ft_is_number(char *str)
{
        int i;
        
        if (!str || !*str)
                return (0);
        i = 0;
        if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
                i++;
        while (str[i])
        {
                if (!ft_isdigit(str[i]))
                        return (0);
                i++;
        }
        return (1);
}

int ft_atoi(char *str, int *number)
{
        int i;
        int sign;
        long nmb;

        i = 0;
        nmb = 0;
        sign = 1;
        if (!number || !ft_is_number(str))
                return (0);
        if (str[i] == '+' || str[i] == '-')
        {
                if (str[i] == '-')
                        sign = -1;
                i++;
        }
        while (str[i] && ft_isdigit(str[i]))
        {
                if (!(ft_int_size_check(sign, nmb, str[i] - '0')))
                        return (0);
                nmb = nmb * 10 + (str[i] - '0');
                i++;
        }
        *number = (int)(nmb * sign);
        return (1);
}