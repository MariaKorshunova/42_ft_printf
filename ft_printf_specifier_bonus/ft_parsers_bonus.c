/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsers_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:50:09 by jmabel            #+#    #+#             */
/*   Updated: 2021/12/12 13:21:47 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	ft_parser(char **p, va_list *ap, int *printed_char)
{
	t_list	pl;

	ft_begin_printed_list(&pl);
	ft_parser_flags(p, &pl);
	pl.fwidth = ft_parser_number(p, ap);
	if (**p == '.')
	{
		(*p)++;
		pl.fprecision = ft_parser_number(p, ap);
	}
	ft_parser_specifier(p, ap, &pl, printed_char);
}

void	ft_begin_printed_list(t_list *pl)
{
	pl->fminus = 0;
	pl->fnull = 0;
	pl->fplus = 0;
	pl->fblank = 0;
	pl->fsharp = 0;
	pl->fwidth = -1;
	pl->fprecision = -1;
	pl->str = NULL;
}

void	ft_parser_flags(char **p, t_list *pl)
{
	if (**p == '-' || **p == '0' || **p == '+' || **p == ' ' || **p == '#')
	{	
		while (**p == '-' || **p == '0' || **p == '+'
			|| **p == ' ' || **p == '#')
		{
			if (**p == '-')
				(*pl).fminus = 1;
			if (**p == '0')
				(*pl).fnull = 1;
			if (**p == '+')
				(*pl).fplus = 1;
			if (**p == ' ')
				(*pl).fblank = 1;
			if (**p == '#')
				(*pl).fsharp = 1;
			(*p)++;
		}
	}
}

int	ft_parser_number(char **p, va_list *ap)
{
	char	*str;
	int		int_value;

	int_value = 0;
	if (**p == '*')
	{
		(*p)++;
		return (va_arg(*ap, int));
	}
	if (ft_isdigit(**p) == 1)
	{
		str = *p;
		while (ft_isdigit(**p) == 1)
		{
			(*p)++;
			int_value++;
		}
		str = ft_substr(str, 0, int_value + 1);
		if (!str)
			return (-1);
		int_value = ft_atoi(str);
		free (str);
	}
	return (int_value);
}

void	ft_parser_specifier(char **p, va_list *ap, t_list *pl, int	*print_char)
{
	if (**p == 'c')
		*print_char += ft_print_single_character(p, ap, pl);
	else if (**p == 's')
		*print_char += ft_print_string_of_characters(p, ap, pl);
	else if (**p == 'p')
		*print_char += ft_print_pointer_argument(p, ap, pl);
	else if (**p == 'i' || **p == 'd')
		*print_char += ft_print_decimal_integer(p, ap, pl);
	else if (**p == 'u')
		*print_char += ft_print_unsigned_decimal(p, ap, pl);
	else if (**p == 'x')
		*print_char += ft_print_hexadecimal_lowercase(p, ap, pl);
	else if (**p == 'X')
		*print_char += ft_print_hexadecimal_uppercase(p, ap, pl);
	else if (**p == '%')
		*print_char += ft_print_percent_sign(p, pl);
}
