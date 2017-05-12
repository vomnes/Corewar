#include "vm.h"

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

void print_memory(t_vm vm, WINDOW *window)
{
	int i;
	int color;

	i = 0;
	color = 0;
	wmove(window, 1, 1);
	while (i < MEM_SIZE)
	{
		if ((color = check_pos_pc(vm, i)))
		{
			wattron(window, COLOR_PAIR(color));
			wprintw(window, "%02x",vm.memory[i]);
			wattroff(window, COLOR_PAIR(color));
		}
		else
			wprintw(window, "%02x", vm.memory[i]);
		if ((i + 1) % 64 == 0)								// a changer pour % 64
			wprintw(window, "\n ");
		else
			wprintw(window, " ");
		i++;
	}
	box(window, 0, 0);
	refresh();
	wrefresh(window);
}


void			init_windows(WINDOW **window) // <<-- a remplacer par une structure WINDOW du nombre de fenetres qu'il faut
{
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLUE);
	init_pair(2, COLOR_YELLOW, COLOR_RED);
	init_pair(3, COLOR_BLUE, COLOR_RED);
	init_pair(4, COLOR_BLUE, COLOR_RED);
	keypad(stdscr, TRUE);

	*window = newwin(66, 193, 0, 0);
}

void			display_all_windows(t_vm vm, WINDOW *window)  // <<-- a remplacer par une structure WINDOW du nombre de fenetres qu'il faut
{
	print_memory(vm, window);
	usleep(5000);
}
