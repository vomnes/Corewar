#include "vm.h"


static int		check_pos_pc(t_vm vm, int i)
{
	t_process *process;
	int		value;

	process = vm.processes;
	while (process)
	{
		value = vm_read_register(process->pc);
		if (value == i && value != 0)
			return (1);
		process = process->next;
	}
	return (0);
}

void print_memory(t_vm vm, WINDOW *window)
{
	int i;
	int j;
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLUE);
	init_pair(2, COLOR_BLUE, COLOR_RED);

	i = 0;
	j = 0;
	wmove(window, 1, 1);
	while (i < MEM_SIZE)
	{
		/*if (check_pos_pc(vm, i))
		{
			attron(COLOR_PAIR(1));
			attrset(COLOR_PAIR(1));
			move((i - (j * 48) - 1),j);
			wprintw(window, "%02x",vm.memory[i]);
			refresh();
		}
		else*/
			wprintw(window, "%.2x", vm.memory[i]);
		if ((i + 1) % 48 == 0)								// a changer pour % 64
		{
			wprintw(window, "\n ");
			j++;
		}	
		else
			wprintw(window, " ");
		i++;
	}
	box(window, 0, 0);
	refresh();
	wrefresh(window);
}


void			init_windows(WINDOW **window)
{
	initscr();
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_RED);
	init_pair(2, COLOR_BLUE, COLOR_RED);
	keypad(stdscr, TRUE);

	*window = newwin(66, 193, 0, 0);
}

void			display_all_windows(t_vm vm, WINDOW *window)
{
	print_memory(vm, window);
}
/*
   int main()
   {
   WINDOW	*win1;
   WINDOW	*win2;
   WINDOW	*win3;
   unsigned char memory[MEM_SIZE];

//	int 	x;
//	int		y;

initscr();
//raw();
//	noecho();
//	cbreak();
keypad(stdscr, TRUE);
win1 = newwin(66, 193, 0, 0);
win2 = newwin(33, 50, 0, 193);
win3 = newwin(33, 50, 33, 193);
//	box(win1, 0, 0);
box(win2, 0, 0);
box(win3, 0, 0);
//	refresh();
//wrefresh(win1);
//efresh(win2);
//	wrefresh(win3);

print_memory(win1, memory);
wrefresh(win1);

getch();
mvwprintw(win2, 1, 1, "hello");
wrefresh(win2);
getch();
endwin();
return (0);
}*/
