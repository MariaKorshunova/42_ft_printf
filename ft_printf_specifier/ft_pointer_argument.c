/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_argument.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:11:56 by jmabel            #+#    #+#             */
/*   Updated: 2021/11/30 14:53:56 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_pointer_argument(char **p, va_list *ap)
{
	unsigned long	number;
	int				printed_char;

	printed_char = 0;
	number = va_arg(*ap, unsigned long);
	ft_putstr_fd("0x", 1);
	printed_char = ft_print_dec_to_hexadec(number, &printed_char, 'l');
	(*p)++;
	return (printed_char + 2);
}
