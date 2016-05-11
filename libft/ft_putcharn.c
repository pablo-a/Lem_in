/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:56:29 by pabril            #+#    #+#             */
/*   Updated: 2016/03/17 12:21:55 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putcharn_fd(char c, size_t number, int file_descriptor)
{
	size_t i;

	i = 0;
	while (i < number)
	{
		ft_putchar_fd(c, file_descriptor);
		i++;
	}
}
