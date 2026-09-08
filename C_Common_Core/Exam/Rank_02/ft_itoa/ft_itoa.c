/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:36:48 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/08/24 19:28:12 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

long ft_count(long nbr)
{
        long result;

        result = 0;
        if(nbr <= 0)
                result ++;
        while(nbr != 0)
        {
                result++;
                nbr /= 10;
        }
        return (result);
}

char	*ft_itoa(int nbr)
{
        long count;
        long m;
        char *result;
        
        m = nbr;
        count = ft_count(m);
        result = malloc( (count + 1) * sizeof (char));
        if(!result)
                return (NULL);
        result[count] = '\0';
        if (m == 0)
                result[0] = '0';
        if (m < 0)
        {
                result[0] = '-';
                m = -m;
        }
        while(m > 0)
        {
                count--;
                result[count] = (m % 10) + '0';
                m /= 10;
        }
        return (result);        
}


int main(void)
{
        char *ptr = ft_itoa(-123);
        printf("%s\n", ptr);
        return(0);
}