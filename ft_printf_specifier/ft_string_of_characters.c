/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_of_characters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:10:32 by jmabel            #+#    #+#             */
/*   Updated: 2021/11/29 15:23:49 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_string_of_characters(char **p, va_list *ap)
{
	char	*str;
	int		printed_char;

	printed_char = 0;
	str = va_arg(*ap, char *);
	if ((!str))
	{
		ft_putstr_fd("(null)", 1);
		printed_char = 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		printed_char = ft_strlen(str);
	}
	(*p)++;
	return (printed_char);
}
