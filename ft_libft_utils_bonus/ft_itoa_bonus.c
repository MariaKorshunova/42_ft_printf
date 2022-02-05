/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:44:58 by jmabel            #+#    #+#             */
/*   Updated: 2021/12/11 17:45:02 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*ft_itoa_record(long long n, int len, char *str)
{
	int	finish;
	int	i;

	finish = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		finish = 1;
	}
	i = len - 1;
	while (i >= finish)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_itoa(long long nb)
{
	char		*str;
	long long	n;
	int			len;

	n = nb;
	len = ft_longlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_itoa_record(n, len, str);
	return (str);
}
