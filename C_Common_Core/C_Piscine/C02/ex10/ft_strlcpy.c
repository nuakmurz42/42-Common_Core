/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:50:15 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/02/02 22:10:45 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	counter;
	unsigned int	index;

	index = 0;
	counter = 0;
	while (src[counter])
		counter++;
	if (size != 0)
	{
		while (src[index] && index < size -1)
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (counter);
}
