/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:57:27 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/07/13 18:50:19 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_putstr_len(const char *str);
int	ft_putchar_len(const char c);
int	ft_putnbr_len(int n);
int	ft_putunsigned_len(unsigned int n);
int	ft_puthex_len(unsigned int n, char x);
int	ft_putpointer_len(unsigned long n);

#endif