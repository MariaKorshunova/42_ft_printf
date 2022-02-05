/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:29:39 by jmabel            #+#    #+#             */
/*   Updated: 2021/12/12 14:30:54 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
			ft_parser(&p, &ap, &printed_char);
		}
	}
	va_end(ap);
	return (printed_char);
}
