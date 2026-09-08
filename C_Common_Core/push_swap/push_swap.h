/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 22:35:38 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/08/12 19:33:55 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>

typedef enum strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;
typedef struct s_options
{
	t_strategy	strategy;
	int			bench;
	int			strategy_seen;
}	t_options;
typedef struct s_list
{
	int				nmb;
	struct s_list	*next;
}	t_list;
//Linked List Tools
t_list	*ft_lstnew(int nmb);
void	ft_lstprint(t_list *lst);
int		ft_lstcounter(t_list *lst);
void	ft_lstadd_front(t_list **head, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	del(int *nmb);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstcut(t_list **head);
//Push Operations
void	ft_pa(t_list **a, t_list **b);
void	ft_pb(t_list **a, t_list **b);
//Swap Operations
void	ft_swap(t_list **head);
void	ft_sa(t_list **a);
void	ft_sb(t_list **b);
void	ft_ss(t_list **a, t_list **b);
//Rotate Operations
void	ft_rotate(t_list **head);
void	ft_ra(t_list **a);
void	ft_rb(t_list **b);
void	ft_rr(t_list **a, t_list **b);
//Reverse Rotate Operations
void	ft_reverse_rotate(t_list **head);
void	ft_rra(t_list **a);
void	ft_rrb(t_list **b);
void	ft_rrr(t_list **a, t_list **b);
//Parser Number
int		ft_isdigit(char c);
int		ft_int_size_check(int sign, long nmb, int digit);
int		ft_is_number(char *str);
int		ft_atoi(char *str, int *number);
//Parser Stack
int		ft_check_duplicate(t_list *a, int number);
int		ft_creator(t_list **lst, char *str);
int		ft_parser_args(t_list **a, t_options *options, int argc, char **argv);
int		ft_helper(t_list **a);
void	ft_start(t_options *options);
//String Tools
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(const char *s, char c);
char	**ft_split_helper(const char *s, char **ptr, char c, int words);
void	ft_free(char **ptr, int j);
void	ft_free_split(char **arr);
static int	ft_word_counter(const char *s, int c);
//Parser Options
void	ft_start(t_options *options);
int		ft_apply_strategy(t_options *options, t_strategy strategy);
int		ft_choose_strategy(t_options *options, char *arg);
int		ft_check_strategy(t_options *options, char *arg);

#endif
