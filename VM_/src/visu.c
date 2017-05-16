#include "vm.h"

static void		print_color_w(t_vm vm, WINDOW *window, int color, int pos)
{
	wattron(window, COLOR_PAIR(color));
	wprintw(window, "%02x",vm.memory[pos]);
	wattroff(window, COLOR_PAIR(color));
}

static void		check_cells(t_vm *vm, WINDOW *window, int pos)
{

	if (vm->cells[pos].present != 0)
		print_color_w(*vm, window, vm->cells[pos].present + 4, pos);
	else if (vm->cells[pos].recent == 1 && vm->cells[pos].count-- > 0)
		print_color_w(*vm, window, 9, pos);
	else if (vm->cells[pos].player_no != 0)
		print_color_w(*vm, window, vm->cells[pos].player_no, pos);
	else
		wprintw(window, "%02x", vm->memory[pos]);
}

void			print_memory(t_vm *vm, WINDOW *window)
{
	static int count = 0;
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

void			print_color_heart(t_vm *vm, WINDOW *window, char *str[16], int pos, int player_no)
{
	int			x;
	int			y;
	int			count;
	int			value;

	getyx(window, y, x);
	count = -1;
	(void)player_no;
	value = (15.0 / vm->cycle_to_die * vm->cycles_since_last_check) + 0.5;
	while (++count <= 14)
	{
		wmove(window, y + count + 2, pos);
		if (count > value || (vm->players[player_no].cycle_of_last_live > (vm->cycle_nbr - vm->cycles_since_last_check)))
		{
			wattron(window, COLOR_PAIR(9));
			wprintw(window, str[count]);
			wattroff(window, COLOR_PAIR(9));
		}
		else
			wprintw(window, str[count]);
	}
}

void			print_heart(WINDOW *window, int pos, t_vm *vm, int player_no)
{
	char *str[16];

	str[0] = "     OOOOOOOO:       OOOOOOOO!";
	str[1] = " oOOOO!!!!;;;;O    OO.......:;!O";
	str[2] = "'OOO!!!;;;;;;;;O  O.......:   ;!O";
	str[3] = "OOO!!!!;;::::::.OO........:    ;!O";
	str[4] = "OO!!!!;;:::::..............:   ;!O";
	str[5] = "OOO!!!;::::::..............:   ;!O";
	str[6] = " OO!!;;::::::.............:   ;!O";
	str[7] = "  OO!;;::::::.............::::!O";
	str[8] = "    O!!;::::::............:::O";
	str[9] = "      !!!;:::::..........ooO";
	str[10] = "         !!;:::::.......O";
	str[11] = "            ;;::::.....O";
	str[12] = "              :::..O";
	str[13] = "                ::.";
	str[14] = "                 :";
	print_color_heart(vm, window, str, pos, player_no);
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
			(ft_strlen(vm->players[i].name) > 30) ? wprintw(window, "[...]") : 1;
			wattroff(window, COLOR_PAIR(vm->players[i].number));
			print_heart(window, x, vm, i);
			getyx(window, y, x);
			if (i % 2 == 0)
				wmove(window, y + 3 , 2);
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
	wprintw(window, "NB_LIVE_SINCE_LAST_CHECK : %d", vm->nb_lives_since_last_check);
}

void			print_info(t_vm *vm, WINDOW *window)
{
	int x;
	int y;

	x = 0;
	y = 0;
// Start & Pause
	wmove(window, 1, 40);
	if (vm->pause == 1)
		wprintw(window, " ** PAUSED **");
	else
		wprintw(window, "** RUNNING **");

//Cycles
	wmove(window, 3 , 2);
	wprintw(window, "Cycles : \t%d ", vm->cycle_nbr);

//Speed_frame
	wmove(window, 4, 70);
	wprintw(window, "Speed : x%03d", vm->speed);

//Processes
	wmove(window, 5 , 2);
	wprintw(window, "Processes : \t%d (Alive : %d)", vm->nb_processes,
			vm->nb_alive_processes);
	

// info_cycle
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
	keypad(stdscr, TRUE);

	windows[1] = newwin(64, 193, 0, 0);
	windows[2] = newwin(64, 100, 0, 194);
	box(windows[2], 0,0);
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
		(vm->pause == 1) ? (vm->pause = 0) : (vm->pause = 1);
	return (entry);
}

void			display_all_windows(t_vm *vm, WINDOW *window[4])  // <<-- a remplacer par une structure WINDOW du nombre de fenetres qu'il faut
{
	int entry;

	entry = check_entry_keys(vm);
	print_memory(vm, window[1]);
	print_info(vm, window[2]);
}
