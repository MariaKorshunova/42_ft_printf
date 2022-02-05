/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_integer_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:34:26 by jmabel            #+#    #+#             */
/*   Updated: 2021/12/12 10:41:47 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	ft_plus_blank_flags(t_list *pl)
{
	char	*str;

	str = ft_strdup(pl->str);
	free(pl->str);
	pl->str = NULL;
	if (!str)
		return ;
	if (pl->fplus == 1 && pl->value >= 0)
		pl->str = ft_strjoin("+", str);
	else
	{
		if (pl->fblank == 1)
			pl->str = ft_strjoin(" ", str);
		else
			pl->str = ft_strdup(str);
	}
	free(str);
	str = NULL;
}

void	ft_print_negative(t_list *pl)
{
	char	*str;

	str = pl->str;
	pl->str = ft_strjoin("-", str);
	free(str);
}

char	*ft_decimal_integer(char **p, va_list *ap, t_list *pl)
{
	int		int_value;
	char	*str;

	(*p)++;
	int_value = va_arg(*ap, int);
	pl->value = int_value;
	if (int_value < 0)
		pl->str = ft_itoa(-1 * (long)(int_value));
	else
		pl->str = ft_itoa(int_value);
	if (!pl->str)
		return (NULL);
	ft_precision(pl, int_value);
	if (!pl->str)
		return (NULL);
	if (int_value >= 0)
		ft_plus_blank_flags(pl);
	if (pl->fwidth > (int)(ft_strlen(pl->str)))
		str = ft_modified_width_str(pl);
	else
		str = ft_strdup(pl->str);
	return (str);
}

int	ft_print_decimal_integer(char **p, va_list *ap, t_list *pl)
{
	int		printed_char;
	char	*str;

	printed_char = 0;
	str = ft_decimal_integer(p, ap, pl);
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
