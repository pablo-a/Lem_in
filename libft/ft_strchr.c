/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:01:32 by pabril            #+#    #+#             */
/*   Updated: 2015/12/01 12:16:10 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *str, int ch)
{
	char *ptr;
	char c;

	ptr = NULL;
	c = (char)ch;
	if (str != NULL)
	{
		while (*str)
		{
			if (*str == c)
			{
				ptr = (char *)str;
				break ;
			}
			str++;
		}
		if (c == '\0')
			ptr = (char *)str;
		return (ptr);
	}
	return (NULL);
}
