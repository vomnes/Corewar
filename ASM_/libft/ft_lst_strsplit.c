/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strsplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 09:47:24 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/24 17:34:45 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t count;
	size_t is_word;
	size_t i;

	count = 0;
	is_word = 0;
	i = 0;
	while (s[++i])
	{
		if (s[i] != c && is_word == 0)
		{
			count++;
			is_word = 1;
		}
		if (s[i] == c)
			is_word = 0;
	}
	return (count);
}

static size_t	*ft_size_words(char const *s, char c)
{
	size_t	*tab;
	size_t	nb_word;
	size_t	i;

	nb_word = 0;
	i = 0;
	tab = (size_t*)ft_memalloc(sizeof(*tab) * (ft_count_words(s, c) * 2 + 1));
	if (!tab)
		return (NULL);
	while (s[i])
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

t_list			*ft_lst_strsplit(char const *s, char c)
{
	t_list	*list;
	t_list	*elem;
	size_t	nb_words;
	size_t	*size_words;
	size_t	k;

	if (!s)
		return (NULL);
	nb_words = ft_count_words(s, c);
	size_words = ft_size_words(s, c);
	list = NULL;
	elem = NULL;
	k = 0;
	while (nb_words--)
	{
		if (!(elem = ft_lstnew(ft_strsub(s, size_words[k], size_words[k + 1]),
		size_words[k + 1] + 1)))
			return (NULL);
		ft_lstadd_end(&list, elem);
		k += 2;
	}
	free(size_words);
	size_words = NULL;
	return (list);
}
