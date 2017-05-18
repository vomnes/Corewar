/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdady <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:32:41 by pdady             #+#    #+#             */
/*   Updated: 2017/05/18 17:41:25 by pdady            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		print_color_w(t_vm vm, WINDOW *window, int color, int pos)
{
	wattron(window, COLOR_PAIR(color));
	wprintw(window, "%02x", vm.memory[pos]);
	wattroff(window, COLOR_PAIR(color));
}

static void		check_cells(t_vm *vm, WINDOW *window, int pos)
{
	if (vm->cells[pos].present != 0)
		print_color_w(*vm, window, vm->cells[pos].player_no + 4, pos);
	else if (vm->cells[pos].recent == 1 && vm->cells[pos].count-- > 0)
		print_color_w(*vm, window, 9, pos);
	else if (vm->cells[pos].player_no != 0)
		print_color_w(*vm, window, vm->cells[pos].player_no, pos);
	else
		print_color_w(*vm, window, 10, pos);
}

void			print_memory(t_vm *vm, WINDOW *window)
{
	static int	count = 0;
	int			i;
	int			color;

	i = -1;
	color = 0;
	wmove(window, 1, 1);
	if (count++ < vm->speed || vm->pause == 1)
		return ;
	else
		count = 0;
	while (++i < MEM_SIZE)
	{
		check_cells(vm, window, i);
		((i + 1) % 64 == 0) ? wprintw(window, "\n ") : wprintw(window, " ");
	}
	box(window, 0, 0);
	wrefresh(window);
}

void			print_heart(t_vm *vm, WINDOW *window, int pos, int player_no)
{
	int			x;
	int			y;
	int			count;
	int			value;

	getyx(window, y, x);
	count = -1;
	value = (15.0 / vm->cycle_to_die * vm->cycles_since_last_check) + 0.5;
	while (++count <= 14)
	{
		wmove(window, y + count + 2, pos);
		if (count >= value || (vm->players[player_no].cycle_of_last_live >
					(vm->cycle_nbr - vm->cycles_since_last_check)))
		{
			wattron(window, COLOR_PAIR(9));
			wprintw(window, vm->heart[count]);
			wattroff(window, COLOR_PAIR(9));
		}
		else
			wprintw(window, vm->heart[count]);
	}
}

static void		print_players(t_vm *vm, WINDOW *window)
{
	int i;
	int x;
	int y;

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
				wprintw(window, "[...]");
			print_heart(vm, window, x, i);
			getyx(window, y, x);
			if (i % 2 == 0)
				wmove(window, y + 3, 2);
			else
				wmove(window, y - 17, 60);
			getyx(window, y, x);
		}
}

void			print_info_vm(t_vm *vm, WINDOW *window)
{
	int x;
	int y;

	getyx(window, y, x);
	wmove(window, y + 3, 2);
	wprintw(window, "Cycles to die : %d ", vm->cycle_to_die);
	getyx(window, y, x);
	wmove(window, y, x + 42);
	wprintw(window, "NB_LIVE_SINCE_LAST_CHECK : %d",
			vm->lives_since_last_check);
}

void			print_info(t_vm *vm, WINDOW *window)
{
	int x;
	int y;

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
	wprintw(window, "Processes : \t%d (Alive : %d)", vm->nb_processes,
			vm->nb_alive_processes);
	print_info_vm(vm, window);
	print_players(vm, window);
	curs_set(0);
	wrefresh(window);
}

void			init_windows(WINDOW **windows)
{
	initscr();
	start_color();
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_MAGENTA);
	init_pair(6, COLOR_CYAN, COLOR_YELLOW);
	init_pair(7, COLOR_MAGENTA, COLOR_CYAN);
	init_pair(8, COLOR_RED, COLOR_BLUE);
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

int			check_entry_keys(t_vm *vm)
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

void			fill_sword_part(char *buf[25])
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
	buf[24] = "         '--'               ^";
}

void			print_sword(WINDOW *window)
{
	char		*buf[32];
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
	fill_sword_part(buf);
	while (++i < 24)
	{
		wmove(window, y + i, x);
		wprintw(window, "%s", buf[i]);
	}
}

void			print_winner_champ(t_vm *vm, WINDOW *window)
{
	t_player *winner;

	wmove(window, 18, 80);
	winner = vm_get_player(vm, vm->last_live_player_no);
	wprintw(window, "Winner : ");
	wattron(window, COLOR_PAIR(winner->number));
	wprintw(window, "%s", winner->name);
	wattroff(window, COLOR_PAIR(winner->number));
	wmove(window, 60, 85);
	wprintw(window, "PRESS (ESC) TO EXIT");
}

void			print_winner(t_vm *vm, WINDOW *window)
{
	(void)window;
	wmove(window, 20, 80);
	print_sword(window);
	print_winner_champ(vm, window);
	wrefresh(window);
	curs_set(0);
	while (check_entry_keys(vm) != 27)
		;
}

void			display_all_windows(t_vm *vm, WINDOW *window[4], char ret)
{
	int entry;

	entry = check_entry_keys(vm);
	if (ret == 1)
	{
		print_memory(vm, window[1]);
		print_info(vm, window[2]);
	}
	else
	{
		print_winner(vm, window[3]);
		print_info(vm, window[2]);
	}
}
