/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:09:10 by pabril            #+#    #+#             */
/*   Updated: 2015/12/01 12:19:45 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*ptr;
	int		length;

	ptr = (char *)s1;
	if (s1 != NULL && s2 != NULL)
	{
		if (!(*s2))
			return (ptr);
		length = ft_strlen(s2);
		while (*ptr)
		{
			if (ft_strncmp(ptr, s2, length) == 0)
				return (ptr);
			ptr++;
		}
		ptr = NULL;
		return (ptr);
	}
	return (NULL);
}
