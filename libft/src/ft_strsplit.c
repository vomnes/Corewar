/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:46:26 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:47:26 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char const *s, char c)
{
	int count;
	int in_string;

	count = 0;
	in_string = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (in_string)
				in_string = 0;
		}
		else if (!in_string)
		{
			in_string = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int	stringlen(char const *s, char c)
{
	int count;

	count = 0;
	while (*s && *s != c)
	{
		count++;
		s++;
	}
	return (count);
}

static char	*duplicate_nth_string(char const *s, char c, int n)
{
	int count;
	int in_string;

	count = 0;
	in_string = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (in_string)
				in_string = 0;
		}
		else if (!in_string)
		{
			in_string = 1;
			count++;
			if (count == n)
				break ;
		}
		s++;
	}
	return (ft_strsub(s, 0, stringlen(s, c)));
}

char		**ft_strsplit(char const *s, char c)
{
	char	**output;
	int		nb_strings;
	int		i;

	if (s)
	{
		nb_strings = count_strings(s, c);
		output = (char **)malloc((nb_strings + 1) * sizeof(*output));
		if (output)
		{
			i = 0;
			while (i < nb_strings)
			{
				output[i] = duplicate_nth_string(s, c, i + 1);
				i++;
			}
			output[i] = NULL;
		}
		return (output);
	}
	return (NULL);
}
