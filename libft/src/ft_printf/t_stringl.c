/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stringl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:47:20 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/30 15:01:31 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_stringl	*str_to_stringl(char *str)
{
	t_stringl	*new;

	new = NULL;
	if (str && (new = (t_stringl *)ft_memalloc(sizeof(t_stringl))))
	{
		new->text = str;
		new->length = ft_strlen(str);
	}
	return (new);
}

void		delete_stringl(t_stringl *stringl)
{
	if (stringl)
		free(stringl->text);
	free(stringl);
}

t_stringl	*append_stringl(t_stringl *strl1, t_stringl *strl2)
{
	char	*new_text;

	if (strl1 && strl2 && strl1->text && strl2->text
		&& (new_text = ft_strnew(strl1->length + strl2->length)))
	{
		ft_memcpy(new_text, strl1->text, strl1->length);
		ft_memcpy(new_text + strl1->length, strl2->text, strl2->length);
		free(strl1->text);
		strl1->text = new_text;
		strl1->length = strl1->length + strl2->length;
		delete_stringl(strl2);
		return (strl1);
	}
	else
	{
		delete_stringl(strl1);
		delete_stringl(strl2);
		return (NULL);
	}
}

t_stringl	*stringlappend_char_before(t_stringl *strl, char character)
{
	char	*new_text;

	if (strl && strl->text && (new_text = ft_strnew(strl->length + 1)))
	{
		new_text[0] = character;
		ft_memcpy(new_text + 1, strl->text, strl->length);
		strl->length += 1;
		ft_strdel(&(strl->text));
		strl->text = new_text;
		return (strl);
	}
	else
	{
		delete_stringl(strl);
		return (NULL);
	}
}

t_stringl	*stringlappend_char(t_stringl *strl, char character)
{
	char	*new_text;

	if (strl && strl->text && (new_text = ft_strnew(strl->length + 1)))
	{
		ft_memcpy(new_text, strl->text, strl->length);
		new_text[strl->length] = character;
		strl->length += 1;
		ft_strdel(&(strl->text));
		strl->text = new_text;
		return (strl);
	}
	else
	{
		delete_stringl(strl);
		return (NULL);
	}
}
