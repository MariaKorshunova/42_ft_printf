/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:24:07 by jmabel            #+#    #+#             */
/*   Updated: 2021/12/11 16:24:11 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		dest[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (i < ft_strlen(s2))
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}

char	*ft_strjoinsymb(char **s1, char c)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc((ft_strlen(*s1) + 2) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < ft_strlen(*s1))
	{
		dest[i] = (*s1)[i];
		i++;
	}
	dest[i] = c;
	dest[i + 1] = '\0';
	free(*s1);
	*s1 = NULL;
	return (dest);
}
