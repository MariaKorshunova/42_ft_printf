/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_argument_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:11:56 by jmabel            #+#    #+#             */
/*   Updated: 2021/12/11 17:35:50 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	ft_pointer_argument(char **p, va_list *ap, t_list *pl)
{
	unsigned long	number;
	int				printed_char;

	(*p)++;
	printed_char = 0;
	number = va_arg(*ap, unsigned long);
	pl->str = (char *)malloc(3);
	if (!pl->str)
		return ;
	ft_record_0x(&(pl->str), 0, 'l');
	ft_str_dec_to_hexadec(number, &(pl->str), "0123456789abcdef");
}

int	ft_print_pointer_argument(char **p, va_list *ap, t_list *pl)
{
	int		printed_char;
	char	*str;

	ft_pointer_argument(p, ap, pl);
	if (!pl->str)
		return (0);
	if (pl->fwidth > (int)(ft_strlen(pl->str)))
		str = ft_modified_width_str(pl);
	else
		str = ft_strdup(pl->str);
	ft_putstr_fd(str, 1);
	printed_char = ft_strlen(str);
	free(pl->str);
	pl->str = NULL;
	free (str);
	str = NULL;
	return (printed_char);
}
