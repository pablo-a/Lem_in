/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:07:15 by pabril            #+#    #+#             */
/*   Updated: 2015/12/01 12:17:06 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char *ptr;
	char c;

	c = (char)ch;
	ptr = NULL;
	if (str != NULL)
	{
		while (*str)
		{
			if (*str == c)
				ptr = (char *)str;
			str++;
		}
		if (*str == c)
			ptr = (char *)str;
		return (ptr);
	}
	return (NULL);
}
