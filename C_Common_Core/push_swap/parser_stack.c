/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 22:27:54 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/07/29 15:37:12 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_duplicate(t_list *a, int number)
{
        t_list *tmp;
        if (!a)
                return (0);
        tmp = a;
        while (tmp != NULL)
        {
                if (tmp->nmb == number)
                        return (1);
                tmp = tmp->next;
        }
        return (0);
}

int ft_creator(t_list **lst, char *str)
{
        int number;
        t_list *new;

        number = 0;
        if (!ft_atoi(str, &number))
                return (0);
        if (!ft_check_duplicate(*lst, number))
        {
                new = ft_lstnew(number);
                if (!new)
                        return (0);
        }
        else
                return (0);
        ft_lstadd_back(lst, new);
        return (1);
}