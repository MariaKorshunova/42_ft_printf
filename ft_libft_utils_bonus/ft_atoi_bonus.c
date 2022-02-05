/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:54:09 by jmabel            #+#    #+#             */
/*   Updated: 2021/12/11 15:54:12 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				minus;
	unsigned int	nb;

	i = 0;
	minus = 1;
	nb = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		minus = -minus;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = 10 * nb + str[i++] - '0';
	if (nb > 2147483647 && minus == 1)
		return (-1);
	if (nb > 2147483648 && minus == -1)
		return (0);
	return (minus * nb);
}
