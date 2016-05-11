/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:00:27 by pabril            #+#    #+#             */
/*   Updated: 2015/12/01 12:35:09 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	d;
	char			*str;

	d = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	str = ft_strnew(len + 1);
	if (str)
	{
		while (i < start)
			i++;
		while (i < start + len)
			str[d++] = s[i++];
	}
	return (str);
}
