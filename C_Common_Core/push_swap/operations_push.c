/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 22:35:16 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/08/12 19:28:43 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_pb(t_list **a, t_list **b)
{
        if (!a || !b)
                return ;
        if (*a == NULL)
                return ;
        ft_lstadd_front(b, ft_lstcut(a));
        write(1, "pb\n", 3);
}

void ft_pa(t_list **a, t_list **b)
{
        if (!a || !b)
                return ;
        if (*b == NULL)
                return ;
        ft_lstadd_front(a, ft_lstcut(b));
        write(1, "pa\n", 3);
}