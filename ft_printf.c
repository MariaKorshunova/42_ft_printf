/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:47:04 by jmabel            #+#    #+#             */
/*   Updated: 2021/11/30 17:13:43 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parser_specifier(char **p, va_list *ap)
{
	int	printed_char;

	printed_char = 0;
	if (**p == 'c')
		printed_char = ft_single_character(p, ap);
	else if (**p == 's')
		printed_char = ft_string_of_characters(p, ap);
	else if (**p == 'p')
		printed_char = ft_pointer_argument(p, ap);
	else if (**p == 'i' || **p == 'd')
		printed_char = ft_decimal_integer(p, ap);
	else if (**p == 'u')
		printed_char = ft_unsigned_decimal(p, ap);
	else if (**p == 'x')
		printed_char = ft_hexadecimal_lowercase(p, ap);
	else if (**p == 'X')
		printed_char = ft_hexadecimal_uppercase(p, ap);
	else if (**p == '%')
		printed_char = ft_percent_sign(p);
	return (printed_char);
}

int	ft_print_dec_to_hexadec(unsigned long number, int *printed_char, char flag)
{
	char	*str;

	if (flag == 'l')
		str = "0123456789abcdef";
	else if (flag == 'u')
		str = "0123456789ABCDEF";
	if (number < 16)
		ft_putchar_fd(str[number], 1);
	else
	{
		(*printed_char)++;
		ft_print_dec_to_hexadec(number / 16, printed_char, flag);
		ft_putchar_fd(str[number % 16], 1);
	}
	return (*printed_char + 1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	*p;
	int		printed_char;

	va_start(ap, fmt);
	p = (char *)fmt;
	printed_char = 0;
	while (*p)
	{
		if (*p != '%')
		{
			write(1, p, 1);
			p++;
			printed_char++;
		}
		else if (*p == '%')
		{
			p++;
			printed_char += ft_parser_specifier(&p, &ap);
		}
	}
	va_end(ap);
	return (printed_char);
}
