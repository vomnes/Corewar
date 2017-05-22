/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdady <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 12:55:14 by pdady             #+#    #+#             */
/*   Updated: 2017/05/22 11:30:39 by pdady            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			init_windows(WINDOW **windows)
{
	initscr();
	start_color();
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(6, COLOR_BLACK, COLOR_YELLOW);
	init_pair(7, COLOR_BLACK, COLOR_CYAN);
	init_pair(8, COLOR_BLACK, COLOR_BLUE);
	init_pair(9, COLOR_RED, COLOR_BLACK);
	init_color(COLOR_GREEN, 104, 104, 103);
	init_pair(10, COLOR_GREEN, COLOR_BLACK);
	keypad(stdscr, TRUE);
	windows[1] = newwin(64, 193, 0, 0);
	windows[2] = newwin(64, 100, 0, 194);
	windows[3] = newwin(64, 193, 0, 0);
	box(windows[2], 0, 0);
	box(windows[3], 0, 0);
}

int				check_entry_keys(t_vm *vm)
{
	int entry;

	entry = 0;
	nodelay(stdscr, 1);
	entry = getch();
	noecho();
	nodelay(stdscr, 0);
	(entry == '+' && vm->speed < 100) ? vm->speed += 10 : 1;
	(entry == '-' && vm->speed > 0) ? vm->speed -= 10 : 1;
	if (entry == 32)
	{
		if (vm->pause == 1)
			vm->pause = 0;
		else
			vm->pause = 1;
	}
	return (entry);
}

void			display_all_windows(t_vm *vm, WINDOW *window[4], char ret)
{
	int entry;

	entry = check_entry_keys(vm);
	if (ret == 1)
	{
		vis_print_memory(vm, window[1]);
		vis_print_info(vm, window[2]);
	}
	else
	{
		werase(window[2]);
		box(window[2], 0, 0);
		vis_print_info(vm, window[2]);
		vis_print_winner(vm, window[3]);
	}
}
