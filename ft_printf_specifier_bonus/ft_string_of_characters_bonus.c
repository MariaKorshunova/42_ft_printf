/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_of_characters_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:10:32 by jmabel            #+#    #+#             */
/*   Updated: 2021/12/11 16:54:22 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	ft_string_of_characters(char **p, va_list *ap, t_list *pl)
{
	pl->str = va_arg(*ap, char *);
	if (!(pl->str))
		pl->str = "(null)";
	(*p)++;
}

int	ft_print_string_of_characters(char **p, va_list *ap, t_list *pl)
{
	int		printed_char;
	char	*str;
	int		is_dynamic;

	is_dynamic = 0;
	ft_string_of_characters(p, ap, pl);
	if (pl->fprecision >= 0 && pl->fprecision < (int)ft_strlen(pl->str))
	{
		pl->str = ft_substr(pl->str, 0, (size_t)pl->fprecision);
		is_dynamic = 1;
	}
	if (!pl->str)
		return (0);
	if (pl->fwidth > (int)(ft_strlen(pl->str)))
		str = ft_modified_width_str(pl);
	else
		str = ft_strdup(pl->str);
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	printed_char = ft_strlen(str);
	if (is_dynamic == 1)
		free(pl->str);
	free (str);
	return (printed_char);
}
