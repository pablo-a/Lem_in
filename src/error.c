/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 10:53:18 by pabril            #+#    #+#             */
/*   Updated: 2016/05/24 13:45:34 by pabril           ###   ########.fr       */
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

int		wrong_map(void)
{
	ft_putendl("WRONG MAP");
	exit(0);
}
