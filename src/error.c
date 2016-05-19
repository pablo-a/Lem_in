/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 10:53:18 by pabril            #+#    #+#             */
/*   Updated: 2016/05/19 11:08:33 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int		incomplete_input(void)
{
	ft_putendl("ERROR");
	exit(0);
}

int		wrong_input(void)
{
	ft_putendl("WRONG INPUT");
	exit(0);
}
