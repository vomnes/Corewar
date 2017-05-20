/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdady <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 13:56:12 by pdady             #+#    #+#             */
/*   Updated: 2017/05/20 15:04:55 by pdady            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			clear_zone(WINDOW *window, int pos, int y)
{
	int			i;

	i = -1;
	while (++i <= 14)
	{
		wmove(window, y + i + 2, pos);
		wprintw(window, "\t\t\t\t\t");
	}
}

static void		draw_it(WINDOW *window, int pos, char *buf[15])
{
	int			x;
	int			y;
	int			i;

	i = -1;
	getyx(window, y, x);
	clear_zone(window, pos, y);
	while (++i <= 14)
	{
		wmove(window, y + i + 2, pos);
		wprintw(window, buf[i]);
	}
}

void			vis_print_skull(WINDOW *window, int pos)
{
	char		*buf[15];

	buf[0] = "                  ______";
	buf[1] = "               .-\"      \"-.";
	buf[2] = "              /            \\";
	buf[3] = "  _          |              |          _";
	buf[4] = " ( \\         |,  .-.  .-.  ,|         / )";
	buf[5] = "  > \"=._     | )(__/  \\__)( |     _.=\" <";
	buf[6] = " (_/\"=._\"=._ |/     /\\     \\| _.=\"_.=\"\\_)";
	buf[7] = "        \"=._ (_     ^^     _)\"_.=\"";
	buf[8] = "            \"=\\__|IIIIII|__/=\"";
	buf[9] = "           _.=\"| \\IIIIII/ |\"=._";
	buf[10] = " _     _.=\"_.=\"\\          /\"=._\"=._     _";
	buf[11] = "( \\_.=\"_.=\"     `--------`     \"=._\"=._/ )";
	buf[12] = " > _.=\"                            \"=._ <";
	buf[13] = "(_/                                    \\_)";
	buf[14] = "";
	draw_it(window, pos, buf);
}

void			vis_print_cup(WINDOW *window, int pos)
{
	char*buf[15];

	buf[0] = ".-..-\"\"``\"\"-..-.";
	buf[1] = "|(`\\`'----'`/`)|";
	buf[2] = " \\\\ ;:.    ; //";
	buf[3] = "  \\\\|:.    |//";
	buf[4] = "   )|:.    |(";
	buf[5] = " ((,|:.    |,))";
	buf[6] = "  '-\\::.   /-'";
	buf[7] = "     '::..'";
	buf[8] = "       }{";
	buf[9] = "      {__}";
	buf[10] = "     /    \\";
	buf[11] = "    |`----'|";
	buf[12] = "    | [#1] |";
	buf[13] = "    '.____.\'";
	buf[14] = "";
	pos += 5;
	draw_it(window, pos, buf);
}
