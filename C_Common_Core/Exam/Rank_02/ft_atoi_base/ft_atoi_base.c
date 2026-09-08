/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 20:12:32 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/08/24 20:54:20 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(const char *str, int str_base)
{
        int result;
        int sign;
        int i;
        int digit;
        
        result = 0;
        i = 0;
        sign = 1;
        if (str[i] == '-')
        {
                sign *= -1;
                i++;
        }
        while(str[i])
        {
                if(str[i] >='0' && str[i]<= '9')
                        digit = (str[i] - '0');
                else if(str[i] >='A' && str[i]<= 'F')
                        digit = (str[i] - 'A' + 10);
                else if(str[i] >='a' && str[i]<= 'f')
                        digit = (str[i] - 'a' + 10);
                else
                        break;
                if (digit >= str_base)
                        break;
                result = result * str_base + digit;
                i++;
        }
        return (result * sign);      
}