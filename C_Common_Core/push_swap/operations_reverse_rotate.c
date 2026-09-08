/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 00:06:23 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/07/28 17:10:25 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_reverse_rotate(t_list **head)
{
        t_list *last;
        t_list *before_last;
        t_list *tmp;

        if (!head || !*head || (*head)->next == NULL)
                return ;
        tmp = *head;
        while (tmp->next->next != NULL)
                tmp = tmp->next;
        before_last = tmp;
        last = tmp->next;
        before_last->next = NULL;
        ft_lstadd_front(head, last);
}

void ft_rra(t_list **a)
{
        if (!a || !*a || (*a)->next == NULL)
                return ;
        ft_reverse_rotate(a);
        write(1, "rra\n", 4);
}
void ft_rrb(t_list **b)
{
        if (!b || !*b || (*b)->next == NULL)
                return ;
        ft_reverse_rotate(b);
        write(1, "rrb\n", 4);
}
void ft_rrr(t_list **a, t_list **b)
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
        ft_reverse_rotate(a);
        ft_reverse_rotate(b);
        write(1, "rrr\n", 4);
}