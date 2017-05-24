/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_print_winner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdady <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 13:23:12 by pdady             #+#    #+#             */
/*   Updated: 2017/05/23 13:24:29 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		fill_sword_part2(char *buf[25])
{
	buf[11] = "|<>   .--------.   <>|     |.|";
	buf[12] = "|     |   ()   |     |     |P|";
	buf[13] = "|_____| (O\\/O) |_____|     |'|";
	buf[14] = "|     \\   /\\   /     |     |.|";
	buf[15] = "|------\\  \\/  /------|     |U|";
	buf[16] = "|       '.__.'       |     |'|";
	buf[17] = "|        |  |        |     |.|";
	buf[18] = ":        |  |        :     |N|";
	buf[19] = " \\<>     |  |     <>/      |'|";
	buf[20] = "  \\<>    |  |    <>/       |.|";
	buf[21] = "   \\<>   |  |   <>/        |K|";
	buf[22] = "    `\\<> |  | <>/'         |'|";
	buf[23] = "      `-.|  |.-`           \\ /";
	buf[24] = "         '--'                  ";
}

static void		print_sword(WINDOW *window)
{
	char		*buf[25];
	int			x;
	int			y;
	int			i;

	i = -1;
	getyx(window, y, x);
	buf[0] = "                           .-.";
	buf[1] = "                          {{@}}";
	buf[2] = "          <>               8@8";
	buf[3] = "        .::::.             888";
	buf[4] = "    @\\\\/W\\/\\/W\\//@         8@8";
	buf[5] = "     \\\\/^\\/\\/^\\//     _    )8(";
	buf[6] = "      \\_O_<>_O_/     (@)__/8@8\\__(@)";
	buf[7] = " ____________________ `~\"-=):(=-\"~`";
	buf[8] = "|<><><>  |  |  <><><>|     |.|";
	buf[9] = "|<>      |  |      <>|     |S|";
	buf[10] = "|<>      |  |      <>|     |'|";
	fill_sword_part2(buf);
	while (++i < 25)
	{
		wmove(window, y + i, x);
		wprintw(window, "%s", buf[i]);
	}
}

static void		print_winner2(t_vm *vm, WINDOW *window)
{
	t_player	*winner;

	wmove(window, 18, 80);
	winner = vm_get_player(vm, vm->last_live_player_no);
	if (winner)
	{
		wprintw(window, "Winner : ");
		wattron(window, COLOR_PAIR(winner->number));
		wprintw(window, "%s", winner->name);
		wattroff(window, COLOR_PAIR(winner->number));
	}
	wmove(window, 57, 85);
	wprintw(window, "PRESS (ESC) TO EXIT");
}

void			vis_print_winner(t_vm *vm, WINDOW *window)
{
	wmove(window, 20, 80);
	print_sword(window);
	print_winner2(vm, window);
	wrefresh(window);
	curs_set(0);
	while (check_entry_keys(vm) != 27)
		;
}
