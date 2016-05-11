/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 10:45:26 by pabril            #+#    #+#             */
/*   Updated: 2016/03/17 12:59:46 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_handle_unsigned(unsigned long long b, t_list *lst)
{
	if (lst->precision == 0 && lst->modified_precision && b == 0 &&
			lst->size == 0 && lst->type != 'o' && lst->type != 'O')
		return (0);
	if (lst->type == 'x' || lst->type == 'X')
	{
		if (lst->zero && (lst->minus == FALSE) && lst->modified_precision == 0)
			ft_printxo_flag0(lst, 16, b);
		else
			ft_printxo(lst, 16, b, 2);
	}
	else if (lst->type == 'o' || lst->type == 'O')
	{
		if (lst->zero && (lst->minus == FALSE) && lst->precision == 0)
			ft_printxo_flag0(lst, 8, b);
		else
			ft_printxo(lst, 8, b, 1);
	}
	else
		ft_print_u(lst, b);
	return (0);
}

int		ft_print_u(t_list *lst, unsigned long long b)
{
	if (lst->minus)
	{
		lst->result += ft_print_zeros(lst->precision, ft_len_uns_number(b));
		lst->result += ft_len_uns_number(b);
		ft_print_number(b);
		lst->result += (lst->precision > ft_len_uns_number(b) ?
				ft_print_space(lst->size - lst->precision) :
				ft_print_space(lst->size - ft_len_uns_number(b)));
	}
	else if (lst->zero && lst->precision == 0 && !lst->modified_precision)
	{
		lst->result += ft_print_zeros(lst->size, ft_len_uns_number(b));
		lst->result += ft_len_uns_number(b);
		ft_print_number(b);
	}
	else
	{
		lst->result += (lst->precision > ft_len_uns_number(b) ?
				ft_print_space(lst->size - lst->precision) :
				ft_print_space(lst->size - ft_len_uns_number(b)));
		lst->result += ft_print_zeros(lst->precision, ft_len_uns_number(b));
		lst->result += ft_len_uns_number(b);
		ft_print_number(b);
	}
	return (0);
}

int		ft_baselen(unsigned long long n, int size, int base)
{
	if (n >= (unsigned long long)base)
		size = ft_baselen(n / base, size, base);
	if (n % base < 10)
		size++;
	else if (n % base >= 10)
		size++;
	return (size);
}

int		ft_putbase(unsigned long long n, int size, int base, t_list *lst)
{
	if (n >= (unsigned long long)base)
		size = ft_putbase(n / base, size, base, lst);
	if (n % base < 10)
		size += ft_print_char((n % base) + '0');
	else if (n % base >= 10)
	{
		if (lst->type == 'o' || lst->type == 'x')
			size += ft_print_char((n % base) - 10 + 'a');
		else
			size += ft_print_char((n % base) - 10 + 'A');
	}
	return (size);
}

int		ft_put_base(unsigned long long nbr, int base, t_list *lst)
{
	int	size;

	size = 0;
	if (base == 8)
		lst->result += ft_putbase(nbr, 0, 8, lst);
	else if (base == 16)
		lst->result += ft_putbase(nbr, 0, 16, lst);
	return (size);
}
