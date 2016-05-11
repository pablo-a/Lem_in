/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 11:33:03 by pabril            #+#    #+#             */
/*   Updated: 2016/04/20 11:58:18 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_cos(double nb)
{
	double	result;
	double	current;
	double	theta;
	int		i;

	i = 0;
	nb = ft_fmod(nb, (2 * 3.141592653589793));
	result = 0.0;
	current = 1.0;
	theta = 0.0001;
	while (ft_fabs(current) >= theta)
	{
		current = (ft_pow(-1, (double)i) * ft_pow(nb, 2 * i)) / ft_fact(2 * i);
		result += current;
		i++;
	}
	return (result);
}
