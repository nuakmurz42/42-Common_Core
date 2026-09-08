/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:07:07 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/07/13 18:53:51 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_helper(va_list args)
{
	unsigned long	ptr;
	int				len;

	len = 0;
	ptr = (unsigned long)va_arg(args, void *);
	if (ptr == 0)
		return (ft_putstr_len("(nil)"));
	len += ft_putstr_len("0x");
	return (len + ft_putpointer_len(ptr));
}

static int	ft_format(const char c, va_list args)
{
	if (c == 's')
		return (ft_putstr_len(va_arg(args, char *)));
	else if (c == 'c')
		return (ft_putchar_len(va_arg(args, int)));
	else if (c == 'd')
		return (ft_putnbr_len(va_arg(args, int)));
	else if (c == 'i')
		return (ft_putnbr_len(va_arg(args, int)));
	else if (c == '%')
		return (ft_putchar_len('%'));
	else if (c == 'u')
		return (ft_putunsigned_len(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex_len(va_arg(args, unsigned int), c));
	else if (c == 'p')
		return (ft_ptr_helper(args));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (!format)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len += ft_format(format[i], args);
		}
		else
			len += ft_putchar_len(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*int main(void)
{
    int ft_len;
    int std_len;

    printf("=== Starting ft_printf Tests ===\n\n");

    // 1. Character Test (%c)
    printf("--- Character (%%c) ---\n");
    ft_len = ft_printf("Mine: %c\n", 'A');
    std_len = printf("Orig: %c\n", 'A');
    printf("Lengths -> ft_printf: %d | printf: %d\n\n", ft_len, std_len);

    // 2. String Test (%s)
    printf("--- String (%%s) ---\n");
    ft_len = ft_printf("Mine: %s\n", "Hello, 42 Warsaw!");
    std_len = printf("Orig: %s\n", "Hello, 42 Warsaw!");
    printf("Lengths -> ft_printf: %d | printf: %d\n\n", ft_len, std_len);

    // 3. Integers Test (%d and %i)
    printf("--- Integers (%%d and %%i) ---\n");
    ft_len = ft_printf("Mine: %d | %i\n", -12345, 42);
    std_len = printf("Orig: %d | %i\n", -12345, 42);
    printf("Lengths -> ft_printf: %d | printf: %d\n\n", ft_len, std_len);

    // 4. Edge Case Integers
    printf("--- Edge Case Integers ---\n");
    ft_len = ft_printf("Mine: %d | %d\n", INT_MAX, INT_MIN);
    std_len = printf("Orig: %d | %d\n", INT_MAX, INT_MIN);
    printf("Lengths -> ft_printf: %d | printf: %d\n\n", ft_len, std_len);

    // 5. Unsigned Integer Test (%u)
    printf("--- Unsigned (%%u) ---\n");
    ft_len = ft_printf("Mine: %u\n", 4294967295U);
    std_len = printf("Orig: %u\n", 4294967295U);
    printf("Lengths -> ft_printf: %d | printf: %d\n\n", ft_len, std_len);

    // 6. Hexadecimal Test (%x and %X)
    printf("--- Hexadecimal (%%x and %%X) ---\n");
    ft_len = ft_printf("Mine: %x | %X\n", 255, 255);
    std_len = printf("Orig: %x | %X\n", 255, 255);
    printf("Lengths -> ft_printf: %d | printf: %d\n\n", ft_len, std_len);

    // 7. Pointer Test (%p)
    printf("--- Pointer (%%p) ---\n");
    int num = 42;
    void *ptr = &num;
    ft_len = ft_printf("Mine: %p\n", ptr);
    std_len = printf("Orig: %p\n", ptr);
    printf("Lengths -> ft_printf: %d | printf: %d\n\n", ft_len, std_len);

    // 8. Null Pointer Test
    printf("--- Null Pointer (%%p) ---\n");
    ft_len = ft_printf("Mine: %p\n", NULL);
    std_len = printf("Orig: %p\n", NULL);
    printf("Lengths -> ft_printf: %d | printf: %d\n\n", ft_len, std_len);

    // 9. Percentage Sign Test (%%)
    printf("--- Percent Sign (%%%%) ---\n");
    ft_len = ft_printf("Mine: 100%%\n");
    std_len = printf("Orig: 100%%\n");
    printf("Lengths -> ft_printf: %d | printf: %d\n\n", ft_len, std_len);

    // 10. Mixed String Test
    printf("--- Mixed String ---\n");
    ft_len = ft_printf("Mine: %c %s %d %x\n", 'X', "test", 100, 100);
    std_len = printf("Orig: %c %s %d %x\n", 'X', "test", 100, 100);
    printf("Lengths -> ft_printf: %d | printf: %d\n\n", ft_len, std_len);

    printf("=== Testing Finished ===\n");
    return (0);
}*/