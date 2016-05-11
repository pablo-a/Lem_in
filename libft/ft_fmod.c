/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 11:41:03 by pabril            #+#    #+#             */
/*   Updated: 2016/04/20 11:41:44 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_fmod(double x, double mod)
{
	double	result;
	double	dec;
	double	ent;

	dec = ft_modf(x, &ent);
	result = ((int)ent % (int)mod) + dec;
	return (result);
}
