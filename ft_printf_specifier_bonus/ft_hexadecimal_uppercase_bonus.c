/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_uppercase_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:01:41 by jmabel            #+#    #+#             */
/*   Updated: 2021/12/12 14:09:55 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*ft_hexadecimal_uppercase(char **p, va_list *ap, t_list *pl)
{
	unsigned int	number;
	char			*str;

	(*p)++;
	number = va_arg(*ap, unsigned int);
	pl->str = (char *)malloc(1);
	if (!pl->str)
		return (NULL);
	(pl->str)[0] = '\0';
	ft_str_dec_to_hexadec(number, &(pl->str), "0123456789ABCDEF");
	if (!pl->str)
		return (NULL);
	ft_precision(pl, number);
	if (pl->fsharp == 1 && number != 0)
		ft_sharp_flags(pl, 'X');
	if (!pl->str)
		return (NULL);
	if (pl->fwidth > (int)(ft_strlen(pl->str)))
		str = ft_modified_width_str(pl);
	else
		str = ft_strdup(pl->str);
	 return (str);
}

int	ft_print_hexadecimal_uppercase(char **p, va_list *ap, t_list *pl)
{
	int		printed_char;
	char	*str;

	printed_char = 0;
	str = ft_hexadecimal_uppercase(p, ap, pl);
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
