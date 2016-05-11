/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 17:35:52 by pabril            #+#    #+#             */
/*   Updated: 2016/03/17 11:53:48 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*change_lenght(char *str, int len, int size)
{
	int		n;
	int		i;
	char	*dst;

	i = -1;
	n = size;
	if (n == len)
		return (str);
	dst = ft_strnew(len);
	if (len < n)
	{
		while (i++ < len - 1)
			dst[i] = str[i];
		return (dst);
	}
	while (i++ < (len - n - 1))
		dst[i] = ' ';
	while (i < len)
	{
		dst[i] = str[i - (len - n)];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*flag_0(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			str[i] = '0';
		i++;
	}
	return (str);
}

char	*blank_flag(char *str)
{
	int a;
	int len;

	a = ft_atoi(str);
	len = ft_strlen(str);
	if (a < 0)
		return (str);
	else
	{
		str = change_lenght(str, len + 1, len);
		return (str);
	}
}

int		diese_flag(t_list *lst)
{
	if (lst->type == 'o' || lst->type == 'O')
	{
		write(1, "0", 1);
		return (1);
	}
	else if (lst->type == 'x')
	{
		write(1, "0x", 2);
		return (2);
	}
	else if (lst->type == 'X')
	{
		write(1, "0X", 2);
		return (2);
	}
	return (0);
}
