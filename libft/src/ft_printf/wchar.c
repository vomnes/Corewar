/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:56:57 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/30 15:23:35 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		fill_unicode_2bytes(char *unicode, wchar_t character)
{
	unsigned char	headmask;
	unsigned char	tailmask;
	unsigned char	tmp;

	headmask = 0xC0;
	tailmask = 0x80;
	if (unicode)
	{
		unicode[0] = headmask | (unsigned char)(character >> 6);
		tmp = (unsigned char)character << 2;
		unicode[1] = tailmask | tmp >> 2;
	}
}

void		fill_unicode_3bytes(char *unicode, wchar_t character)
{
	unsigned char	headmask;
	unsigned char	tailmask;
	unsigned char	tmp;

	headmask = 0xE0;
	tailmask = 0x80;
	if (unicode)
	{
		unicode[0] = headmask | (unsigned char)(character >> 12);
		tmp = (unsigned char)(character >> 4);
		unicode[1] = tailmask | tmp >> 2;
		tmp = (unsigned char)(character << 2);
		unicode[2] = tailmask | tmp >> 2;
	}
}

void		fill_unicode_4bytes(char *unicode, wchar_t character)
{
	unsigned char	headmask;
	unsigned char	tailmask;
	unsigned char	tmp;

	headmask = 0xF0;
	tailmask = 0x80;
	if (unicode)
	{
		unicode[0] = headmask | (unsigned char)(character >> 18);
		tmp = (unsigned char)(character >> 10);
		unicode[1] = tailmask | tmp >> 2;
		tmp = (unsigned char)(character >> 4);
		unicode[2] = tailmask | tmp >> 2;
		tmp = (unsigned char)(character << 2);
		unicode[3] = tailmask | tmp >> 2;
	}
}

char		*convert_wchar(wchar_t character)
{
	char *unicode;

	unicode = NULL;
	if (character < 0 || (character >= 0xD800 && character <= 0xDFFF))
		return (unicode);
	if (character < 0x80)
		unicode = ft_strappend_char(unicode, (char)character);
	else if (character < 0x800)
	{
		unicode = ft_strnew(2);
		fill_unicode_2bytes(unicode, character);
	}
	else if (character < 0x10000)
	{
		unicode = ft_strnew(3);
		fill_unicode_3bytes(unicode, character);
	}
	else if (character < 0x10FFFF)
	{
		unicode = ft_strnew(4);
		fill_unicode_4bytes(unicode, character);
	}
	return (unicode);
}

char		*convert_wstring(wchar_t *wstring)
{
	char	*converted_string;
	char	*converted_wchar;

	converted_string = NULL;
	if (wstring)
	{
		converted_string = ft_strnew(0);
		while (converted_string && *wstring)
		{
			converted_wchar = convert_wchar(*wstring);
			if (converted_wchar)
				converted_string = ft_strdeljoin(converted_string,
											converted_wchar);
			wstring++;
		}
	}
	return (converted_string);
}
