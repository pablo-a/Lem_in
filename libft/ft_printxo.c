/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printxo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 12:11:08 by pabril            #+#    #+#             */
/*   Updated: 2016/04/01 18:26:17 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_printxo_flag0(t_list *lst, int base, unsigned long long nb)
{
	if (lst->diese)
	{
		lst->result += diese_flag(lst);
		lst->result += ft_print_zeros(lst->size - (base == 8 ? 1 : 2),
				ft_baselen(nb, 0, base));
		ft_put_base(nb, base, lst);
	}
	else
	{
		lst->result += ft_print_zeros(lst->size, ft_baselen(nb, 0, base));
		ft_put_base(nb, base, lst);
	}
	return (0);
}

int		ft_printxo(t_list *lst, int base, unsigned long long nb, int spaces)
{
	if (lst->minus)
	{
		if (lst->diese)
		{
			lst->result += diese_flag(lst);
			lst->result += ft_print_zeros(lst->precision - ((base == 8) ? 1 :
					0), ft_baselen(nb, 0, base));
			ft_put_base(nb, base, lst);
			lst->result += (lst->precision > ft_baselen(nb, 0, base) ?
					ft_print_space(lst->size - lst->precision - base) :
					ft_print_space(lst->size - ft_baselen(nb, 0, base) -
						spaces));
			return (0);
		}
		lst->result += ft_print_zeros(lst->precision, ft_baselen(nb, 0, base));
		ft_put_base(nb, base, lst);
		lst->result += (lst->precision > ft_baselen(nb, 0, base) ?
				ft_print_space(lst->size - lst->precision) :
				ft_print_space(lst->size - ft_baselen(nb, 0, base)));
		return (0);
	}
	else
		ft_printxo2(lst, base, nb, spaces);
	return (0);
}

int		ft_printxo2(t_list *lst, int base, unsigned long long nb, int spaces)
{
	if (lst->diese && nb)
	{
		lst->result += (lst->precision > ft_baselen(nb, 0, base) ?
				ft_print_space(lst->size - lst->precision - spaces) :
				ft_print_space(lst->size - ft_baselen(nb, 0, base) -
					spaces));
		lst->result += diese_flag(lst);
		lst->result += ft_print_zeros(lst->precision -
				((base == 8) ? 1 : 0),
				ft_baselen(nb, 0, base));
		ft_put_base(nb, base, lst);
		return (0);
	}
	if (lst->precision == 0 && lst->modified_precision && !lst->diese && !nb)
	{
		lst->result += ft_print_space(lst->size);
		return (0);
	}
	lst->result += ((lst->precision > ft_baselen(nb, 0, base)) ?
			ft_print_space(lst->size - lst->precision) :
			ft_print_space(lst->size - ft_baselen(nb, 0, base)));
	lst->result += ft_print_zeros(lst->precision, ft_baselen(nb, 0, base));
	ft_put_base(nb, base, lst);
	return (0);
}
