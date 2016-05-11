/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 11:37:12 by pabril            #+#    #+#             */
/*   Updated: 2016/04/20 11:37:44 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double nb, long pow)
{
	long	i;
	double	result;

	i = 0;
	if (pow < 0)
		nb = 1 / nb;
	result = 1.0;
	while (ft_abs(i) < ft_labs(pow))
	{
		result *= nb;
		i++;
	}
	return (result);
}
