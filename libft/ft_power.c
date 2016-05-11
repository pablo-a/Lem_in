/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <pabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:34:58 by pabril            #+#    #+#             */
/*   Updated: 2016/03/17 12:16:46 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long			ft_power(int a, int pow)
{
	long long	result;
	int			i;

	result = 1;
	i = 0;
	while (i < pow)
	{
		result *= a;
		i++;
	}
	return (result);
}

unsigned long long	ft_power_unsigned(int a, int pow)
{
	unsigned long long	result;
	int					i;

	result = 1;
	i = 0;
	while (i < pow)
	{
		if (a == 16 && i == 15)
			return (result);
		if (a == 8 && i == 21)
			return (result);
		result *= a;
		i++;
	}
	return (result);
}
