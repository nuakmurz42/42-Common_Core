/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 22:35:25 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/08/12 19:32:24 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_lstlast(t_list *lst)
{
        t_list *last;

        if (lst == NULL)
                return (lst);
        last = lst;
        while (last->next != NULL)
                last = last->next;
        return (last);
}

t_list *ft_lstnew(int nmb)
{
        t_list *lst;

        lst = malloc (sizeof(t_list));
        if (!lst)
                return (NULL);
        lst->nmb = nmb;
        lst ->next = NULL;
        return (lst);
}

void ft_lstprint(t_list *lst)
{
        t_list *tmp;

        if (!lst)
                return ;
        tmp = lst;
        while(tmp != NULL)
        {
                printf("%d  ", tmp->nmb);
                tmp = tmp->next;
        }

}
int ft_lstcounter(t_list *lst)
{
        int counter;
        t_list *tmp;

        counter = 0;
        tmp = lst;
        while (tmp != NULL)
        {
                counter++;
                tmp = tmp->next;
        }
        return (counter);
}

void ft_lstadd_front(t_list **head, t_list *new)
{
        if (head == NULL || new == NULL)
                return ;
        new->next = *head;
        *head = new;
}
void ft_lstadd_back(t_list **lst, t_list *new)
{
        t_list *last;
        
        if (!lst || !new)
                return ;
        if (!*lst)
        {
                *lst = new;
                return ;
        }
        last = ft_lstlast (*lst);
        last->next = new;
}


void ft_lstdelone(t_list *lst)
{
        if (!lst)
                return ;
        free (lst);
}

void ft_lstclear(t_list **lst)
{
        t_list *tmp;

        if (!lst)
                return ;
        while (*lst != NULL)
        {
                tmp = (*lst)->next;
                ft_lstdelone (*lst);
                *lst = tmp;
        }
}

t_list *ft_lstcut(t_list **head)
{
        t_list *first;

        if (!head)
                return (NULL);
        if (!*head)
                return (NULL);
        first = *head;
        *head = (*head)->next;
        first->next = NULL;
        return (first);
}