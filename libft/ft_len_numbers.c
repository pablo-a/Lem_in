/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 12:19:37 by pabril            #+#    #+#             */
/*   Updated: 2016/03/17 12:21:09 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_len_number(long long int n)
{
	int result;

	result = 0;
	if (n == 0)
		return (1);
	while (n / 10 > 0 || n / 10 < 0)
	{
		n /= 10;
		result++;
	}
	result++;
	return (result);
}

int		ft_len_uns_number(unsigned long long int n)
{
	int result;

	result = 0;
	while (n / 10 > 0)
	{
		n /= 10;
		result++;
	}
	result++;
	return (result);
}
