/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:44:36 by pabril            #+#    #+#             */
/*   Updated: 2016/03/15 11:24:42 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_print_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_print_char(str[i]);
		i++;
	}
	return (i);
}

int		ft_print_space(int i)
{
	int k;

	k = 0;
	if (i <= 0)
		return (0);
	while (k < i)
	{
		write(1, " ", 1);
		k++;
	}
	return (i);
}

int		ft_print_sign(long long int i)
{
	if (i < 0)
		write(1, "-", 1);
	else
		write(1, "+", 1);
	return (1);
}

int		ft_print_number(unsigned long long int n)
{
	if (n > 9)
	{
		ft_print_number(n / 10);
		ft_print_number(n % 10);
	}
	else
		ft_print_char('0' + n);
	return (0);
}
