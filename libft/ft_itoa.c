/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:23:53 by pabril            #+#    #+#             */
/*   Updated: 2015/12/04 16:37:09 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_recursive(char **str, int n)
{
	if (n > 9)
	{
		ft_itoa_recursive(str, n / 10);
		ft_itoa_recursive(str, n % 10);
	}
	else
	{
		**str = n + '0';
		(*str)++;
	}
}

char		*ft_itoa(int n)
{
	char *str;
	char *result;

	str = ft_strnew(12);
	if (n == -2147483648)
	{
		str = "-2147483648";
		return (str);
	}
	result = str;
	if (!str)
		return (NULL);
	if (n < 0)
	{
		*str = '-';
		n = -n;
		str++;
	}
	ft_itoa_recursive(&str, n);
	return (result);
}

int			main(void)
{
	ft_putstr(ft_itoa(12345678));
	return (0);
}
