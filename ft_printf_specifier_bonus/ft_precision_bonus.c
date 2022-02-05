/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:59:35 by jmabel            #+#    #+#             */
/*   Updated: 2021/12/11 16:12:06 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	ft_fill_precision(t_list *pl, char *str)
{
	char	*str_mod;

	str_mod = (char *)malloc((pl->fprecision
				- (int)(ft_strlen(str)) + 1) * sizeof(char));
	if (!str_mod)
		return ;
	str_mod = ft_fillstrbysymb(str_mod, '0',
			pl->fprecision - (int)(ft_strlen(str)));
	pl->str = ft_strjoin(str_mod, str);
	free(str_mod);
	str_mod = NULL;
}

void	ft_exception_zero_precision(t_list *pl)
{
	char	*str_mod;

	str_mod = (char *)malloc(1);
	if (!str_mod)
		return ;
	str_mod[0] = '\0';
	pl->str = ft_strdup(str_mod);
	free(str_mod);
	str_mod = NULL;
}

void	ft_precision(t_list *pl, long long value)
{
	char	*str;

	str = ft_strdup(pl->str);
	free(pl->str);
	pl->str = NULL;
	if (!str)
		return ;
	if (pl->fprecision == 0 && value == 0)
		ft_exception_zero_precision(pl);
	else
	{
		if (pl->fprecision > (int)(ft_strlen(str)))
			ft_fill_precision(pl, str);
		else
			pl->str = ft_strdup(str);
	}
	if (value < 0)
		ft_print_negative(pl);
	free(str);
	str = NULL;
}
