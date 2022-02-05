/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_single_character_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:08:56 by jmabel            #+#    #+#             */
/*   Updated: 2021/12/06 14:31:20 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	ft_print_character_with_width(char c, t_list *pl)
{
	char		*str_mod;
	int			printed_char;

	str_mod = (char *)malloc(pl->fwidth * sizeof(char));
	if (!str_mod)
		return (0);
	str_mod = ft_fillstrbysymb(str_mod, ' ', pl->fwidth - 1);
	if (pl->fminus == 1)
	{
		ft_putchar_fd(c, 1);
		ft_putstr_fd(str_mod, 1);
	}
	else
	{
		ft_putstr_fd(str_mod, 1);
		ft_putchar_fd(c, 1);
	}
	printed_char = (int)ft_strlen(str_mod) + 1;
	free(str_mod);
	str_mod = NULL;
	return (printed_char);
}

int	ft_print_single_character(char **p, va_list *ap, t_list *pl)
{
	int		len;
	char	c;

	(*p)++;
	c = va_arg(*ap, int);
	len = 1;
	if (pl->fwidth > 1)
		len = ft_print_character_with_width(c, pl);
	else
		ft_putchar_fd(c, 1);
	return (len);
}
