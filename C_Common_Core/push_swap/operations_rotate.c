/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 22:51:50 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/07/28 17:08:08 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rotate(t_list **head)
{
        if (!head)
                return ;
        if(*head == NULL || (*head)->next == NULL)
                return ;
        ft_lstadd_back(head, ft_lstcut(head));
}
void ft_ra(t_list **a)
{
        if (!a || !*a || (*a)->next == NULL)
                return ;
        ft_rotate(a);
        write(1, "ra\n", 3);
}
void ft_rb(t_list **b)
{
        if (!b || !*b || (*b)->next == NULL)
                return ;
        ft_rotate(b);
        write(1, "rb\n", 3);
}
void ft_rr(t_list **a, t_list **b)
{
        int     flag_a;
        int     flag_b;

        flag_a = 1;
        flag_b = 1;
        if (!a || !*a || (*a)->next == NULL)
                flag_a = 0;
        if (!b || !*b || (*b)->next == NULL)
                flag_b = 0;
        if (!flag_a && !flag_b)
                return ;
        ft_rotate(a);
        ft_rotate(b);
        write(1, "rr\n", 3);
}