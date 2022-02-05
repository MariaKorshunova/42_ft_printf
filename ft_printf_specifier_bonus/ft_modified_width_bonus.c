/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modified_width_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:50:08 by jmabel            #+#    #+#             */
/*   Updated: 2021/12/12 11:09:15 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*ft_modified_width_str(t_list *pl)
{
	char	*str_mod;
	char	*str;
	int		len;

	len = (int)(ft_strlen(pl->str));
	if (!pl->str)
		return (NULL);
	str_mod = (char *)malloc((pl->fwidth - len + 1) * sizeof(char));
	if (!str_mod)
		return (NULL);
	if (pl->fnull == 1 && pl->fprecision == -1)
		str_mod = ft_fillstrbysymb(str_mod, '0', pl->fwidth - len);
	else
		str_mod = ft_fillstrbysymb(str_mod, ' ', pl->fwidth - len);
	if (pl->fminus == 1)
		str = ft_strjoin(pl->str, str_mod);
	else
		str = ft_strjoin(str_mod, pl->str);
	ft_replace_sign_width(pl, str, len);
	free(str_mod);
	str_mod = NULL;
	return (str);
}

void	ft_replace_sign_width(t_list *pl, char *str, int len)
{
	if (pl->value < 0 && pl->fnull == 1 && pl->fprecision == -1)
	{
		str[0] = str[pl->fwidth - len];
		str[pl->fwidth - len] = '0';
	}
	if (pl->fplus == 1 && pl->fnull == 1 && pl->fprecision == -1)
	{
		str[0] = str[pl->fwidth - len];
		str[pl->fwidth - len] = '0';
	}
}
