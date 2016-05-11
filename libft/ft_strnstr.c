/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:10:55 by pabril            #+#    #+#             */
/*   Updated: 2015/12/01 12:20:35 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*ptr;
	size_t	length;

	ptr = (char *)s1;
	if (s1 != NULL && s2 != NULL)
	{
		if (!(*s2))
			return (ptr);
		length = ft_strlen(s2);
		while (n && *ptr)
		{
			if (length > n)
				return (ptr = NULL);
			if (ft_strncmp(ptr, s2, length) == 0)
				return (ptr);
			ptr++;
			n--;
		}
		ptr = NULL;
		return (ptr);
	}
	return (NULL);
}
