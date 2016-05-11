/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 14:51:22 by pabril            #+#    #+#             */
/*   Updated: 2016/04/01 18:12:50 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.h"

int		ft_ptr(unsigned long n, int size, unsigned long base)
{
	if (n >= base)
		size = ft_ptr(n / base, size, base);
	if (n % base < 10)
		size += ft_print_char((n % base) + '0');
	else if (n % base >= 10)
		size += ft_print_char((n % base) - 10 + 'a');
	return (size);
}

int		ft_ptr_case(t_list *lst, va_list *ap)
{
	unsigned long long ptr;

	ptr = (unsigned long long)va_arg(*ap, void *);
	if (lst->minus)
	{
		lst->result += ft_print_str("0x");
		lst->result += ft_ptr(ptr, 0, 16);
		lst->result += ft_print_space(lst->size - ft_len_uns_number(ptr) - 2);
	}
	else
	{
		lst->result += ft_print_space(lst->size - ft_len_uns_number(ptr) - 2);
		lst->result += ft_print_str("0x");
		lst->result += ft_ptr(ptr, 0, 16);
	}
	return (0);
}
