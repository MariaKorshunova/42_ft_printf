/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:12:58 by jmabel            #+#    #+#             */
/*   Updated: 2021/11/29 15:23:20 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_decimal_integer(char **p, va_list *ap)
{
	int	int_value;
	int	printed_char;

	int_value = va_arg(*ap, int);
	ft_putnbr_fd(int_value, 1);
	printed_char = ft_longlen((long long)int_value);
	(*p)++;
	return (printed_char);
}
