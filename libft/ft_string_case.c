/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:29:50 by pabril            #+#    #+#             */
/*   Updated: 2016/03/27 17:15:49 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_char_case(t_list *lst, va_list *ap)
{
	char c;

	if (lst->type == 'c' && !lst->l)
	{
		c = va_arg(*ap, int);
		if (lst->size > 1)
		{
			if (!lst->minus)
				lst->result += ft_print_space(lst->size - 1);
			lst->result += ft_print_char(c);
			if (lst->minus)
				lst->result += ft_print_space(lst->size - 1);
		}
		else
			lst->result += ft_print_char(c);
	}
	else if ((lst->type == 'c' && lst->l) || lst->type == 'C')
	{
		print_wchar((wchar_t)va_arg(*ap, wint_t), lst);
		return (0);
	}
	else if (lst->type == 's' || lst->type == 'S')
		ft_string_case(lst, ap);
	return (0);
}

int		ft_aff_str(char *str, t_list *lst, int len)
{
	if (lst->size > len)
	{
		if (lst->minus)
		{
			lst->result += ft_print_str(str);
			lst->result += ft_print_space(lst->size - len);
		}
		else
		{
			lst->result += ft_print_space(lst->size - len);
			lst->result += ft_print_str(str);
		}
	}
	else
		lst->result += ft_print_str(str);
	return (0);
}

int		ft_string_case(t_list *lst, va_list *ap)
{
	char	*tempo;
	char	*str;
	size_t	len;

	if (lst->type == 's' && !lst->l)
	{
		if ((tempo = va_arg(*ap, char *)) == NULL)
		{
			lst->result += ft_print_str("(null)");
			return (0);
		}
		len = ft_strlen(tempo);
		if ((str = ft_strnew(len + 1)) == 0)
			return (0);
		str = ft_strncpy(str, tempo, len);
		ft_string_case2(lst, str, len);
	}
	else if (lst->l || lst->type == 'S')
		print_wide_chars(va_arg(*ap, wchar_t*), lst);
	return (0);
}

int		ft_string_case2(t_list *lst, char *str, size_t len)
{
	if ((size_t)lst->precision < len && lst->precision >= 0 &&
			lst->modified_precision)
	{
		str[lst->precision] = '\0';
		ft_aff_str(str, lst, lst->precision);
	}
	else
		ft_aff_str(str, lst, len);
	return (0);
}
