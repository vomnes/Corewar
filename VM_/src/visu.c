#include "vm.h"
/*
static int		check_pos_pc(t_vm vm, int i)
{
	t_process *process;
	int		value;

	process = vm.processes;
	while (process)
	{
		value = vm_read_register(process->pc);
		if (value == i && value != 0 && process->alive == 1)
			return (process->player_no);
		process = process->next;
	}
	return (0);
}
*/
void		print_color_w(t_vm vm, WINDOW *window, int color, int pos)
{
	wattron(window, COLOR_PAIR(color));
	wprintw(window, "%02x",vm.memory[pos]);
	wattroff(window, COLOR_PAIR(color));
}

void		check_cells(t_vm *vm, WINDOW *window, int pos)
{
	//int		color;

	if ((color = check_pos_pc(*vm, pos)))
	//if (vm->cells[pos].present != 0)
		print_color_w(*vm, window, vm->cells[pos].present + 2, pos);
	else if (vm->cells[pos].recent == 1 && vm->cells[pos].count-- > 0)
		print_color_w(*vm, window, 5, pos);
	else if (vm->cells[pos].player_no != 0)
		print_color_w(*vm, window, vm->cells[pos].player_no, pos);
	else
		wprintw(window, "%02x", vm->memory[pos]);
}

void		print_memory(t_vm *vm, WINDOW *window)
{
	static int count = 0;
	int		i;
	int		color;

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

void			print_info(WINDOW *window)
{
	wrefresh(window);
}

void			init_windows(WINDOW **window) // <<-- a remplacer par une structure WINDOW du nombre de fenetres qu'il faut
{
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLUE);
	init_pair(4, COLOR_BLUE, COLOR_RED);
	init_pair(5, COLOR_BLACK, COLOR_WHITE);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	keypad(stdscr, TRUE);

	window[1] = newwin(64, 193, 0, 0);
	window[2] = newwin(70, 60, 0, 194);
	box(window[2], 0,0);
}

int			check_entry_keys(t_vm *vm)
{
	int entry;

	entry = 0;
	nodelay(stdscr, 1);
	entry = getch();
	noecho();
	nodelay(stdscr, 0);
	(entry == '+') ? vm->speed += 10 : 1;
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
	print_info(window[2]);
	//usleep(2000);
}
