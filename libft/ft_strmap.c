/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:44:14 by pabril            #+#    #+#             */
/*   Updated: 2015/12/01 12:28:04 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	str = ft_strnew(ft_strlen(s) + 1);
	i = 0;
	if (str)
	{
		while (s[i])
		{
			str[i] = f(s[i]);
			i++;
		}
	}
	return (str);
}
