/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:57:07 by pabril            #+#    #+#             */
/*   Updated: 2015/12/01 11:52:55 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	result;

	result = 0;
	if (src != NULL && dst != NULL)
	{
		d = (char *)ft_memchr(dst, '\0', size);
		if (d == NULL)
			return (size + ft_strlen(src));
		s = (char *)src;
		result = (size_t)(d - dst) + ft_strlen(src);
		while ((size_t)(d - dst) < size - 1 && *s != '\0')
		{
			*d = *s;
			d++;
			s++;
		}
		*d = '\0';
	}
	return (result);
}
