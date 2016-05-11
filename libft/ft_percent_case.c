/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:15:11 by pabril            #+#    #+#             */
/*   Updated: 2016/03/15 10:55:28 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_percent_case(t_list *lst)
{
	if (lst->size > 1)
	{
		if (lst->minus)
		{
			lst->result += ft_print_char('%');
			lst->result += ft_print_space(lst->size - 1);
			return (0);
		}
		else if (lst->zero)
			lst->result += ft_print_zeros(lst->size, 1);
		else
			lst->result += ft_print_space(lst->size - 1);
		lst->result += ft_print_char('%');
	}
	else
		lst->result += ft_print_char('%');
	return (0);
}
