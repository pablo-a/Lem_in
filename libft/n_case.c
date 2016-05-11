/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 10:52:43 by pabril            #+#    #+#             */
/*   Updated: 2016/03/27 17:48:47 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_n_case(t_list *lst, va_list *ap)
{
	int *n;

	n = va_arg(*ap, int *);
	*n = lst->result;
	return (0);
}

int		ft_color(const char *format)
{
	if (ft_strncmp(format, "stop", 4) == 0)
		ft_print_str(END);
	else if (ft_strncmp(format, "red", 3) == 0)
		ft_print_str(RED);
	else if (ft_strncmp(format, "blue", 4) == 0)
		ft_print_str(BLUE);
	else if (ft_strncmp(format, "green", 5) == 0)
		ft_print_str(GREEN);
	else if (ft_strncmp(format, "purple", 6) == 0)
		ft_print_str(PURPLE);
	else if (ft_strncmp(format, "gray", 4) == 0)
		ft_print_str(GRAY);
	else if (ft_strncmp(format, "yellow", 6) == 0)
		ft_print_str(YELLOW);
	else
		exit(0);
	return (1);
}
