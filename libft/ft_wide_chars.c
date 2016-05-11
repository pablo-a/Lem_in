/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:10:58 by pabril            #+#    #+#             */
/*   Updated: 2016/03/27 17:12:34 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		print_wchar(wint_t wint, t_list *lst)
{
	int size;

	if (wint < 0)
		return (0);
	else if (wint <= 0x7F)
		size = 1;
	else if (wint <= 0x7FF)
		size = 2;
	else if (wint <= 0xFFFF)
		size = 3;
	else if (wint <= 0x10FFFF)
		size = 4;
	else
		return (0);
	if (lst->minus)
	{
		print_wint(wint, lst);
		lst->result += ft_print_space(lst->size - size);
	}
	else
	{
		lst->result += ft_print_space(lst->size - size);
		print_wint(wint, lst);
	}
	return (0);
}

void	print_wint(wint_t wint, t_list *lst)
{
	char str[4];

	if (wint <= 0x7F)
		print_chars(&wint, 1, lst);
	else if (wint <= 0x7FF)
	{
		str[0] = (((wint & 0x07c0) >> 6) + 0xc0);
		str[1] = ((wint & 0x003F) + 0x80);
		print_chars(str, 2, lst);
	}
	else if (wint <= 0xFFFF)
	{
		str[0] = (((wint & 0xF000) >> 12) + 0xE0);
		str[1] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[2] = ((wint & 0x003F) + 0x80);
		print_chars(str, 3, lst);
	}
	else if (wint <= 0x10FFFF)
	{
		str[0] = (((wint & 0x1c0000) >> 18) + 0xF0);
		str[1] = (((wint & 0x03F000) >> 12) + 0x80);
		str[2] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[3] = ((wint & 0x003F) + 0x80);
		print_chars(str, 4, lst);
	}
}

size_t	count_wide_chars(t_list *lst, wchar_t *string, size_t *length)
{
	size_t	i;
	size_t	total_bytes;
	int		add;

	i = 0;
	add = 0;
	total_bytes = 0;
	while (i < *length)
	{
		if (string[i] <= 0x7F)
			add = 1;
		else if (string[i] <= 0x7FF)
			add = 2;
		else if (string[i] <= 0xFFFF)
			add = 3;
		else if (string[i] <= 0x10FFFF)
			add = 4;
		if (lst->modified_precision && (total_bytes + add) >
				(unsigned long)lst->precision)
			break ;
		total_bytes += add;
		i++;
	}
	*length = i;
	return (total_bytes);
}

int		place_padding(char padder, size_t width, t_list *lst)
{
	ft_putcharn_fd(padder, width, 1);
	lst->result += width;
	return (width);
}

int		print_wide_chars(wchar_t *string, t_list *lst)
{
	size_t	i;
	size_t	total_bytes;
	size_t	length;

	if (string == NULL)
	{
		lst->result += ft_print_str("(null)");
		return (0);
	}
	length = ft_strlen_wide(string);
	total_bytes = count_wide_chars(lst, string, &length);
	if (!lst->minus && (unsigned long)lst->size > total_bytes)
		place_padding((lst->zero ? '0' : ' '), lst->size - total_bytes, lst);
	i = 0;
	while (i < length)
	{
		print_wint(string[i], lst);
		i++;
	}
	if (lst->minus && (unsigned long)lst->size > total_bytes)
		place_padding(' ', lst->size - total_bytes, lst);
	return (0);
}
