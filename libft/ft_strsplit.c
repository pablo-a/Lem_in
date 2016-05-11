/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:10:01 by pabril            #+#    #+#             */
/*   Updated: 2015/12/04 16:38:26 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		ft_split_len(const char *s, char c)
{
	int len;

	len = 0;
	while (s[len] != c)
		len++;
	return (len);
}

static	void	ft_remplissage_tab(char **tab, const char *s, char c)
{
	int index;
	int len;

	index = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		len = ft_split_len(s, c);
		tab[index] = ft_strsub(s, 0, len);
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
		index++;
	}
}

static	int		ft_split_nb(const char *s, char c)
{
	int i;
	int nb;

	nb = 0;
	i = 1;
	while (s[i++])
		if (s[i] == c && s[i - 1] != c)
			nb++;
	return (nb);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		nb;

	nb = ft_split_nb(s, c);
	tab = (char **)malloc((sizeof(char *) * nb + 1));
	if (!tab)
		return (NULL);
	ft_remplissage_tab(tab, s, c);
	return (tab);
}
