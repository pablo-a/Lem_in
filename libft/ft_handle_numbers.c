/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:39:06 by pabril            #+#    #+#             */
/*   Updated: 2016/03/17 12:58:46 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_handle_signed(long long a, t_list *lst)
{
	if (lst->precision == 0 && lst->modified_precision && a == 0
				&& lst->size == 0)
		return (0);
	if (lst->minus == FALSE)
	{
		if (lst->plus || (lst->plus && lst->blanck))
			ft_plus_case(a, lst, 1);
		else if (lst->zero && !lst->precision)
			ft_zero(a, lst);
		else if (lst->blanck)
			ft_blanck(a, lst);
		else
			ft_noflag(a, lst, 1);
	}
	else
	{
		if (lst->plus || (lst->plus && lst->blanck))
			ft_plus_case(a, lst, 0);
		else if (lst->blanck)
			ft_blanck(a, lst);
		else
			ft_noflag(a, lst, 0);
	}
	return (0);
}

int		ft_print_precision(long long a, t_list *lst)
{
	lst->result += ft_print_zeros(lst->precision, ft_len_number(a));
	if (lst->precision == 0 && lst->modified_precision && a == 0)
	{
		lst->result += ft_print_char(' ');
		return (0);
	}
	lst->result += ft_putnbr_signed(a);
	return (0);
}

void	ft_plus_case(long long a, t_list *lst, int flag)
{
	if (flag == 0)
	{
		lst->result += ft_print_sign(a);
		ft_print_precision(a, lst);
		lst->result += (lst->precision > ft_len_number(a) ?
				ft_print_space(lst->size - lst->precision - 1) :
				ft_print_space(lst->size - ft_len_number(a) - 1));
		return ;
	}
	if (lst->precision > ft_len_number(a))
	{
		lst->result += ft_print_space(lst->size - lst->precision - 1);
		lst->result += ft_print_sign(a);
	}
	else if (lst->zero)
	{
		lst->result += ft_print_sign(a);
		lst->result += ft_print_zeros(lst->size, ft_len_number(a) + 1);
	}
	else
	{
		lst->result += ft_print_space(lst->size - ft_len_number(a) - 1);
		lst->result += ft_print_sign(a);
	}
	ft_print_precision(a, lst);
}

int		ft_zero(long long a, t_list *lst)
{
	if (lst->blanck && a >= 0)
	{
		lst->result += ft_print_space(1);
		lst->result += ft_print_zeros(lst->size - 1, ft_len_number(a));
	}
	else if (a < 0)
	{
		lst->result += ft_print_sign(a);
		lst->result += ft_print_zeros(lst->size - 1, ft_len_number(a));
	}
	else
		lst->result += ft_print_zeros(lst->size, ft_len_number(a));
	lst->result += ft_putnbr_signed(a);
	return (0);
}

int		ft_blanck(long long a, t_list *lst)
{
	if (a >= 0)
	{
		lst->result += ft_print_space(1);
		if (lst->zero && lst->precision == 0)
			lst->result += ft_print_space(lst->size - ft_len_number(a) - 1);
		else if (lst->precision > ft_len_number(a))
			lst->result += ft_print_space(lst->size - lst->precision - 1);
		else
			lst->result += ft_print_space(lst->size - ft_len_number(a) - 1);
		lst->result += ft_print_zeros(lst->precision, ft_len_number(a));
	}
	else
	{
		lst->result += ft_print_sign(a);
		if (lst->precision > ft_len_number(a))
			lst->result += ft_print_space(lst->size - lst->precision - 1);
		else
			lst->result += ft_print_space(lst->size - ft_len_number(a) - 1);
		lst->result += ft_print_zeros(lst->precision, ft_len_number(a));
	}
	lst->result += ft_putnbr_signed(a);
	return (0);
}
