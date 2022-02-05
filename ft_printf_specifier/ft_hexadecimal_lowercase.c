/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_lowercase.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:35:02 by jmabel            #+#    #+#             */
/*   Updated: 2021/11/30 14:56:28 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_hexadecimal_lowercase(char **p, va_list *ap)
{
	unsigned int	number;
	int				printed_char;

	printed_char = 0;
	number = va_arg(*ap, unsigned int);
	printed_char = ft_print_dec_to_hexadec(number, &printed_char, 'l');
	(*p)++;
	return (printed_char);
}
