/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 15:08:11 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/08/18 15:30:29 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_find_newline(char *stash)
{
	int	i;

	if (stash == NULL)
		return (-1);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == ';')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1 && s1[i])
		i++;
	while (s2 && s2[j])
		j++;
	ptr = malloc(i + j + 1);
	if (!ptr)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (free(s1), ptr);
}
