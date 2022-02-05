/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexademical_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:49:33 by jmabel            #+#    #+#             */
/*   Updated: 2021/12/11 18:50:16 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	ft_str_dec_to_hexadec(unsigned long number, char **str, char *key)
{
	char	*temp;

	if (!(**str) && (**str != 0))
		return ;
	if (number < 16)
	{
		temp = ft_strjoinsymb(str, key[number]);
		if (!temp)
		{
			free(*str);
			return ;
		}
		*str = temp;
	}
	else
	{
		ft_str_dec_to_hexadec(number / 16, str, key);
		temp = ft_strjoinsymb(str, key[number % 16]);
		if (!temp)
		{
			free(*str);
			return ;
		}
		*str = temp;
	}
}

void	ft_record_0x(char **str, int i, char flag)
{
	(*str)[i] = '0';
	if (flag == 'l')
		(*str)[i + 1] = 'x';
	if (flag == 'u')
		(*str)[i + 1] = 'X';
	(*str)[i + 2] = '\0';
}

void	ft_sharp_flags(t_list *pl, char x_case)
{
	char	*str;

	if (!pl->str)
		return ;
	str = ft_strdup(pl->str);
	free(pl->str);
	pl->str = NULL;
	if (!str)
		return ;
	if (x_case == 'x')
		pl->str = ft_strjoin("0x", str);
	else if (x_case == 'X')
		pl->str = ft_strjoin("0X", str);
	free (str);
	str = NULL;
}
