/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:09:23 by pabril            #+#    #+#             */
/*   Updated: 2015/12/01 11:48:01 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[i])
			i++;
		while (s2[j])
			s1[i++] = s2[j++];
		s1[i] = s2[j];
		return (s1);
	}
	return (NULL);
}
