/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:12:54 by pabril            #+#    #+#             */
/*   Updated: 2016/04/01 17:47:57 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

int		restart(t_list **lst)
{
	(*lst)->diese = FALSE;
	(*lst)->zero = FALSE;
	(*lst)->minus = FALSE;
	(*lst)->plus = FALSE;
	(*lst)->blanck = FALSE;
	(*lst)->l = FALSE;
	(*lst)->ll = FALSE;
	(*lst)->h = FALSE;
	(*lst)->hh = FALSE;
	(*lst)->j = FALSE;
	(*lst)->z = FALSE;
	(*lst)->size = 0;
	(*lst)->modified_precision = 0;
	(*lst)->precision = 0;
	(*lst)->type = ' ';
	return (0);
}

int		ft_initialize(t_list **lst)
{
	(*lst)->diese = FALSE;
	(*lst)->zero = FALSE;
	(*lst)->minus = FALSE;
	(*lst)->plus = FALSE;
	(*lst)->blanck = FALSE;
	(*lst)->l = FALSE;
	(*lst)->ll = FALSE;
	(*lst)->h = FALSE;
	(*lst)->hh = FALSE;
	(*lst)->j = FALSE;
	(*lst)->z = FALSE;
	(*lst)->size = 0;
	(*lst)->modified_precision = 0;
	(*lst)->precision = 0;
	(*lst)->type = ' ';
	(*lst)->result = 0;
	return (0);
}

int		ft_store_options(const char *format, int *i, t_list *lst, va_list *ap)
{
	int n;

	n = ft_check_flags(format, *i, &(lst));
	(*i) += n;
	n = ft_check_lenght(format, *i, &(lst), ap);
	(*i) += n;
	n = ft_check_precision(format, *i, &(lst), ap);
	(*i) += n;
	n = ft_check_modifiers(format, *i, &lst);
	(*i) += n;
	n = ft_check_type(format, *i, &(lst->type));
	return (0);
}

int		ft_subprintf(const char *format, int *i, t_list *lst, va_list *ap)
{
	restart(&lst);
	(*i)++;
	ft_store_options(format, i, lst, ap);
	if (lst->type == 'n')
		ft_n_case(lst, ap);
	if (lst->type == 'p')
		ft_ptr_case(lst, ap);
	else if (lst->type == 'c' || lst->type == 'C' || lst->type == 's'
			|| lst->type == 'S')
		ft_char_case(lst, ap);
	else if (lst->type == '%')
		ft_percent_case(lst);
	else
		ft_number_case(lst, ap);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	int				i;
	t_list			*lst;

	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (0);
	ft_initialize(&lst);
	i = -1;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '{' && ft_strncmp(format + i, "{COLOR", 6) == 0)
		{
			ft_color(&(format[i + 7]));
			while (format[i] != '}')
				i++;
		}
		else if (format[i] == '%')
			ft_subprintf(format, &i, lst, &ap);
		else
			lst->result += ft_print_char(format[i]);
	}
	va_end(ap);
	return (lst->result);
}
