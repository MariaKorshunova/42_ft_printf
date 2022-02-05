/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:22:48 by jmabel            #+#    #+#             */
/*   Updated: 2021/11/29 15:23:57 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_unsigned_decimal(char **p, va_list *ap)
{
	unsigned int	un_int_value;
	int				printed_char;

	un_int_value = va_arg(*ap, unsigned int);
	ft_putnbr_unsigned(un_int_value, 1);
	printed_char = ft_longlen((long long)un_int_value);
	(*p)++;
	return (printed_char);
}
