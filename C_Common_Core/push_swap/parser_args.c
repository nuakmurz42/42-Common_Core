/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:42:10 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/08/12 19:37:34 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_helper(t_list **a)
{
        ft_lstclear(a);
        write (2, "Error\n", 6);
        return (0); 
}

int ft_parser_args(t_list **a, t_options *options, int argc, char **argv)
{
        int     i;
        int     flag;

        i = 1;
        while (i < argc)
        {
                flag = ft_check_strategy(options, argv[i]);
                if (flag == 0)
                {
                        if (!ft_creator(a, argv[i]))
                                return (ft_helper(a));
                }
                else if (flag == -1)
                        return (ft_helper(a));
                i++;
        }
        return (1);
}