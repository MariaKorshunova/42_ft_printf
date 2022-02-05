/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:22:48 by jmabel            #+#    #+#             */
/*   Updated: 2021/12/07 18:50:32 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*ft_unsigned_decimal(char **p, va_list *ap, t_list *pl)
{
	unsigned int	un_int_value;
	char			*str;

	(*p)++;
	un_int_value = va_arg(*ap, unsigned int);
	pl->str = ft_itoa(un_int_value);
	if (!pl->str)
		return (NULL);
	ft_precision(pl, un_int_value);
	if (!pl->str)
		return (NULL);
	if (pl->fwidth > (int)(ft_strlen(pl->str)))
		str = ft_modified_width_str(pl);
	else
		str = ft_strdup(pl->str);
	return (str);
}

int	ft_print_unsigned_decimal(char **p, va_list *ap, t_list *pl)
{
	int		printed_char;
	char	*str;

	printed_char = 0;
	str = ft_unsigned_decimal(p, ap, pl);
	if (!str)
	{
		free(pl->str);
		return (0);
	}
	ft_putstr_fd(str, 1);
	printed_char = ft_strlen(str);
	free(str);
	str = NULL;
	free(pl->str);
	pl->str = NULL;
	return (printed_char);
}
