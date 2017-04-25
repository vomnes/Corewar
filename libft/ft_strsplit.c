/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:53:45 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/24 17:36:23 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *s, char c)
{
	int count;
	int i;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (((s[i - 1] == '\0') && (s[i] != c)) ||
			((s[i] == c) && (s[i + 1] != c && s[i + 1] != '\0')))
			count++;
		i++;
	}
	return (count);
}

static int		*ft_size_words(char const *s, char c)
{
	int	*tab;
	int	nb_word;
	int	i;

	if (!s)
		return (0);
	nb_word = 0;
	i = 0;
	tab = (int *)ft_memalloc(sizeof(int*) * (ft_count_words(s, c) * 2 + 1));
	if (!tab)
		return (NULL);
	while (s[i] != '\0')
	{
		if ((s[i - 1] == c || s[i - 1] == '\0') && (s[i] != c))
			tab[nb_word] = i;
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			tab[nb_word + 1] = i - tab[nb_word] + 1;
			nb_word += 2;
		}
		i++;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_words;
	int		*size_words;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	nb_words = ft_count_words(s, c);
	size_words = ft_size_words(s, c);
	if (!(tab = (char**)ft_memalloc(sizeof(*tab) * (nb_words + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (k < nb_words * 2)
	{
		if (!(tab[i] = ft_strsub(s, size_words[k], size_words[k + 1])))
			return (NULL);
		i++;
		k += 2;
	}
	free(size_words);
	return (tab);
}
