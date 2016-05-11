/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:47:17 by pabril            #+#    #+#             */
/*   Updated: 2016/04/19 13:50:30 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_struct	*ft_lstmap(t_struct *lst, t_struct *(*f)(t_struct *elemt))
{
	t_struct *tempo;
	t_struct *tempo_late;
	t_struct *ret;
	t_struct *save;

	tempo_late = NULL;
	save = NULL;
	while (lst != NULL && f != NULL)
	{
		ret = f(lst);
		tempo = ft_lstnew(ret->content, ret->content_size);
		if (tempo == NULL)
			return (NULL);
		tempo->next = NULL;
		if (tempo_late != NULL)
			tempo_late->next = tempo;
		tempo_late = tempo;
		lst = lst->next;
		if (save == NULL)
			save = tempo;
	}
	return (save);
}
