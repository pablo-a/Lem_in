/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:06:44 by pabril            #+#    #+#             */
/*   Updated: 2015/12/01 12:37:40 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	debut;
	size_t	fin;

	if (s == NULL)
		return (NULL);
	debut = 0;
	fin = ft_strlen(s) - 1;
	while (*s && (s[debut] == ' ' || s[debut] == '\n' || s[debut] == '\t'))
		debut++;
	while ((s[fin] == ' ' || s[fin] == '\n' || s[fin] == '\t') && fin > debut)
		fin--;
	str = ft_strnew(fin - debut + 1);
	if (str)
		ft_strncpy(str, s + debut, fin - debut + 1);
	return (str);
}
