/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:57:49 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/08/24 18:10:39 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
        t_list *prev;
        t_list *cur;
        t_list *tmp;
        

        cur = *begin_list;
        prev = 0;
        while(cur)
        {
                if(cmp (cur->data, data_ref) == 0)
                {
                        tmp = cur->next;
                        if (prev)
                        {
                                prev->next = tmp;
                        }
                        else
                        {
                                *begin_list = tmp;
                        }
                        free(cur);
                        cur = tmp;

                }
                else{
                        prev = cur;
                        cur = cur->next;
                }
        }
}