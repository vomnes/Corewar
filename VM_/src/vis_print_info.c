/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_print_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdady <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 13:50:54 by pdady             #+#    #+#             */
/*   Updated: 2017/05/20 14:38:42 by pdady            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		print_color_heart(char *str, int color, WINDOW *window)
{
	wattron(window, COLOR_PAIR(color));
	wprintw(window, "%s", str);
	wattroff(window, COLOR_PAIR(color));
}

static void		print_heart(t_vm *vm, WINDOW *window, int pos, int player_no)
{
	int		x;
	int		y;
	int		count;
	int		value;

	getyx(window, y, x);
	count = -1;
	value = (15.0 / vm->cycle_to_die * vm->cycles_since_last_check);
	if (vm->nb_alive_processes == 0 && vm->last_live_player_no == player_no)
		vis_print_cup(window, pos);
	else if (vm->players[player_no].nb_alive_processes == 0 ||
			vm->nb_alive_processes == 0)
		vis_print_skull(window, pos);
	else
		while (++count < 15)
		{
			wmove(window, y + count + 2, pos);
			if (count >= value || (vm->players[player_no].cycle_of_last_live >
						(vm->cycle_nbr - vm->cycles_since_last_check)))
				print_color_heart(vm->heart[count], 9, window);
			else
				wprintw(window, "\t\t\t\t\t");
		}
}

static void		print_players(t_vm *vm, WINDOW *window)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	wmove(window, 23, 2);
	getyx(window, y, x);
	while (++i <= MAX_PLAYERS)
		if (vm->players[i].number != 0)
		{
			wprintw(window, "Player %d : ", vm->players[i].number);
			wattron(window, COLOR_PAIR(vm->players[i].number));
			wmove(window, y + 1, x + 1);
			wprintw(window, "%.30s", vm->players[i].name);
			wattroff(window, COLOR_PAIR(vm->players[i].number));
			if (ft_strlen(vm->players[i].name) > 30)
				wprintw(window, " [...]");
			print_heart(vm, window, x, i);
			getyx(window, y, x);
			if (i % 2 == 0)
				wmove(window, y + 3, 2);
			else
				wmove(window, y - 17, 56);
			getyx(window, y, x);
		}
}

static void		print_info_vm(t_vm *vm, WINDOW *window)
{
	int			x;
	int			y;

	getyx(window, y, x);
	wmove(window, y + 3, 2);
	wprintw(window, "Cycles to die : %d ", vm->cycle_to_die);
	getyx(window, y, x);
	wmove(window, y, x + 42);
	wprintw(window, "NB_LIVE_SINCE_LAST_CHECK : %d",
			vm->lives_since_last_check);
}

void			vis_print_info(t_vm *vm, WINDOW *window)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	wmove(window, 1, 40);
	if (vm->pause == 1)
		wprintw(window, " ** PAUSED **");
	else
		wprintw(window, "** RUNNING **");
	wmove(window, 3, 2);
	wprintw(window, "Cycles : \t%d ", vm->cycle_nbr);
	wmove(window, 4, 70);
	wprintw(window, "Speed : x%03d", vm->speed);
	wmove(window, 5, 2);
	wprintw(window, "Processes : \t%d (Alive : %d)\t\t", vm->nb_processes,
			vm->nb_alive_processes);
	print_info_vm(vm, window);
	print_players(vm, window);
	curs_set(0);
	wrefresh(window);
}
