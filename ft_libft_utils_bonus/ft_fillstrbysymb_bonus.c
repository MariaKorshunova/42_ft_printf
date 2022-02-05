/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstrbysymb_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:55:17 by jmabel            #+#    #+#             */
/*   Updated: 2021/12/11 15:55:19 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*ft_fillstrbysymb(char *str, char c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}
