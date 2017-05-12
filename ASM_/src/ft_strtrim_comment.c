/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:04:32 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/11 16:09:15 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ft_delete_spaces(char const *s, size_t *index, \
char comment_char, char flg)
{
	if (flg == 1)
	{
		while (s[(*index) - 1] == ' ' || s[(*index) - 1] == '\n' ||\
		s[(*index) - 1] == '\t')
		{
			if (s[(*index) - 1] == comment_char)
				break ;
			(*index)--;
		}
	}
	else
	{
		while (s[*index] == ' ' || s[*index] == '\n' || s[*index] == '\t')
		{
			if (s[*index] == comment_char)
				break ;
			(*index)++;
		}
	}
}

static void	ft_delete_comment(char const *s, size_t index, \
size_t *len, char comment_char)
{
	size_t i;
	char inside_comment;

	i = index;
	inside_comment = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\"')
			inside_comment ^= 1;
		if (s[i] == comment_char && inside_comment == 0)
		{
			*len = i;
			break ;
		}
		i++;
	}
}

/*
** ft_strtrim_comment : Return a char* with the content paramter s without
** space at the start and the end of the string, with the comment deleted.
** Example:
** ft_strtrim_comment("		Hello 		World#my new comment	", '#');
** -->|Hello 		World|
*/

char		*ft_strtrim_comment(char *s, char comment_char)
{
	char	*new_str;
	size_t	index;
	size_t	len;
	int		new_len;

	if (!s)
		return (NULL);
	index = 0;
	len = ft_strlen((char*)s);
	ft_delete_spaces(s, &index, comment_char, 0);
	ft_delete_spaces(s, &len, comment_char, 1);
	ft_delete_comment(s, index, &len, comment_char);
	new_len = len - index;
	(new_len <= 0) ? new_len = 0 : (void)new_len;
	if (!(new_str = ft_strsub(s, index, new_len)))
		return (NULL);
	return (new_str);
}
