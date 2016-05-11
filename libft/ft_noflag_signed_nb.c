/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noflag_signed_nb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:55:20 by pabril            #+#    #+#             */
/*   Updated: 2016/03/17 12:56:09 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_noflag(long long a, t_list *lst, int flag)
{
	if (!flag)
	{
		if (a < 0)
		{
			lst->result += ft_print_sign(a);
			lst->result += ft_print_zeros(lst->precision, ft_len_number(a));
			lst->result += ft_putnbr_signed(a);
			lst->result += (lst->precision > ft_len_number(a) ?
					ft_print_space(lst->size - lst->precision - 1) :
					ft_print_space(lst->size - ft_len_number(a) - 1));
			return (0);
		}
		ft_print_precision(a, lst);
		lst->result += (lst->precision > ft_len_number(a) ?
				ft_print_space(lst->size - lst->precision) :
				ft_print_space(lst->size - ft_len_number(a)));
	}
	else
		ft_noflag2(a, lst);
	return (0);
}

int		ft_noflag2(long long a, t_list *lst)
{
	if (a < 0)
	{
		lst->result += (lst->precision > ft_len_number(a) ?
				ft_print_space(lst->size - lst->precision - 1) :
				ft_print_space(lst->size - ft_len_number(a) - 1));
		lst->result += ft_print_sign(a);
		ft_print_precision(a, lst);
		return (0);
	}
	lst->result += (lst->precision > ft_len_number(a) ?
			ft_print_space(lst->size - lst->precision) :
			ft_print_space(lst->size - ft_len_number(a)));
	ft_print_precision(a, lst);
	return (0);
}
