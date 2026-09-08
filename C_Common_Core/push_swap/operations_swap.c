/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 22:35:10 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/07/28 01:08:32 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_list **head)
{
        t_list *first;
        t_list *second;
        t_list *third;

        if (!head || !*head || (*head)->next == NULL)
                return ;
        first = *head;
        second = first->next;
        third = second->next;
        second->next = first;
        first->next = third;
        *head = second;
}

void ft_sa(t_list **a)
{
        if (!a || !*a || (*a)->next == NULL)
                return ;
        ft_swap(a);
        write(1, "sa\n", 3);
}
void ft_sb(t_list **b)
{
        if (!b || !*b || (*b)->next == NULL)
                return ;
        ft_swap(b);
        write(1, "sb\n", 3);
}

void ft_ss(t_list **a, t_list **b)
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
        ft_swap(a);
        ft_swap(b);
        write(1, "ss\n", 3);
}