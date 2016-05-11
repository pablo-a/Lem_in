/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:50:32 by pabril            #+#    #+#             */
/*   Updated: 2016/04/19 13:51:58 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_struct **alst, t_struct *new)
{
	t_struct *tempo;

	if (new == NULL)
		return ;
	tempo = *alst;
	while (tempo->next != NULL)
		tempo = tempo->next;
	tempo->next = new;
}
