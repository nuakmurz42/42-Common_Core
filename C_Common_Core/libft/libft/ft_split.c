/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 19:47:50 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/07/01 21:35:36 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_counter(const char *s, int c)
{
	int	counter;
	int	flag;
	int	i;

	counter = 0;
	i = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != (char) c && flag == 0)
		{
			counter ++;
			flag = 1;
		}
		else if (s[i] == (char) c)
			flag = 0;
		i++;
	}
	return (counter);
}

static void	ft_free(char **ptr, int j)
{
	while (j > 0)
	{
		j--;
		free(ptr[j]);
	}
	free(ptr);
}

static char	**ft_helper(const char *s, char **ptr, char c, int words)
{
	int		j;
	size_t	i;
	size_t	start;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		ptr[j] = ft_substr(s, start, i - start);
		if (!ptr[j])
		{
			ft_free(ptr, j);
			return (NULL);
		}
		j++;
	}
	ptr[j] = NULL;
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	int		words;

	if (!s)
		return (NULL);
	words = ft_word_counter(s, c);
	ptr = malloc((words + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	return (ft_helper(s, ptr, c, words));
}
/*
#include <stdio.h>
static void	print_and_free(char **arr)
{
	int	i;

	if (!arr)
	{
		printf("NULL\n");
		return ;
	}
	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	main(void)
{
	print_and_free(ft_split("", '\0'));
	print_and_free(ft_split(NULL, ' '));
	print_and_free(ft_split("", ' '));
	print_and_free(ft_split("    ", ' '));
	print_and_free(ft_split("abc", '\0'));
	print_and_free(ft_split("abc", ' '));
	print_and_free(ft_split("a b c", ' '));
	return (0);
}*/
