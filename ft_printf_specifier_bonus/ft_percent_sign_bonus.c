/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_sign_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:28:52 by jmabel            #+#    #+#             */
/*   Updated: 2021/12/12 13:18:57 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	ft_print_percent_sign(char **p, t_list *pl)
{
	int		len;
	char	c;

	(*p)++;
	c = '%';
	len = 1;
	if (pl->fwidth > 1)
		len = ft_print_character_with_width('%', pl);
	else
		ft_putchar_fd(c, 1);
	return (len);
}
