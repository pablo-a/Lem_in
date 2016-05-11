/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:53:48 by pabril            #+#    #+#             */
/*   Updated: 2015/12/01 11:04:42 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	*tempo;
	int				index;
	int				limit;

	limit = len;
	index = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	tempo = (unsigned char *)malloc(len);
	while (len--)
	{
		tempo[index] = s2[index];
		index++;
	}
	index = 0;
	while (index < limit)
	{
		s1[index] = tempo[index];
		index++;
	}
	return ((unsigned char *)dst);
}
