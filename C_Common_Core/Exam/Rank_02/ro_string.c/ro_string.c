/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ro_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 20:58:15 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/08/24 21:27:29 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int print_words(char *str, int start)
{
        int i;
        int flag;
        
        i = start;
        flag = 0;
        while(str[i])
        {
                while(str[i] && (str[i] == ' ' || str[i] == '\t'))
                        i++;
                if(str[i] && flag)
                        write (1, " ", 1);
                while(str[i] && (str[i] != ' ' && str[i] != '\t'))
                {        
                        write(1, &str[i], 1);
                        i++;
                        flag = 1;
                }           
        }
        return (flag);
}

void last_word(char *str, int start, int end)
{
        while(str[start] && start < end)
        {
                write(1, &str[start], 1);
                start++;
        }
}


int main(int argc, char **argv)
{
        int i;
        int wc;

        if(argc >= 2)
        {
                i = 0;
                while(argv[1][i]&& (argv[1][i] == ' ' || argv[1][i] == '\t'))
                        i++;
                wc = i;
                while(argv[1][i]&& (argv[1][i] != ' ' || argv[1][i] != '\t'))
                        i++;
                if (print_words(argv[1], i))
                        write(1, " ", 1);
                last_word(argv[1], wc, i);
        }
        write(1, "\n", 2);
        return (0);
}