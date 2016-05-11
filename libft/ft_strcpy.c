/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:01:12 by pabril            #+#    #+#             */
/*   Updated: 2015/12/01 13:20:40 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dst, const char *src)
{
	char *dest2;

	dest2 = dst;
	if (src != NULL && dst != NULL)
	{
		while (*src)
		{
			*dst++ = *src++;
		}
		*dst = '\0';
		return (dest2);
	}
	return (NULL);
}
