/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_wide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:02:03 by pabril            #+#    #+#             */
/*   Updated: 2016/03/17 12:24:06 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

size_t	ft_strlen_wide(const wchar_t *original)
{
	const wchar_t*end;

	end = original;
	while (*end != L'\0')
		end++;
	return (end - original);
}
