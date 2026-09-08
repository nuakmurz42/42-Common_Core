/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:35:53 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/07/29 19:36:07 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_start(t_options *options)
{
        if (!options)
                return ;
        options->strategy = ADAPTIVE;
        options->bench = 0;
        options->strategy_seen = 0;
}

int ft_apply_strategy(t_options *options, t_strategy strategy)
{
        if (!options)
                return (-1);
        if (options->strategy_seen == 1)
                return (-1);
        options->strategy = strategy;
        options->strategy_seen = 1;
        return (1);
}
int ft_choose_strategy(t_options *options, char *arg)
{
        if (ft_strncmp(arg, "--simple", sizeof("--simple")) == 0)
                return (ft_apply_strategy(options, SIMPLE));
        else if(ft_strncmp(arg, "--medium", sizeof("--medium")) == 0)
                return (ft_apply_strategy(options, MEDIUM));
        else if(ft_strncmp(arg, "--complex", sizeof("--complex")) == 0)
                return (ft_apply_strategy(options, COMPLEX));
        else if(ft_strncmp(arg, "--adaptive", sizeof("--adaptive")) == 0)
                return (ft_apply_strategy(options, ADAPTIVE));
        return (0);
}

int ft_check_strategy(t_options *options, char *arg)
{
        int flag;

        if (!options || !arg)
                return (-1);
        flag = ft_choose_strategy(options, arg);
        if (flag == 1)
                return (1);
        else if (flag == -1)
                return (-1);
        else if (flag == 0 && ft_strncmp(arg, "--bench", sizeof("--bench")) == 0)
        {
                options->bench = 1;
                return (1);
        }
        return (0);
}