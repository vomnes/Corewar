#include "vm.h"

int			print_usage(void)
{
	ft_printf("Usage: ./corewar [-a -vis -d N -v N] <champion1.cor> <...>\n");
	ft_printf("\t-a\t: Prints output from 'aff' (Default is to hide it)\n");
	ft_printf("\t-vis\t: Ncurses output mode\n");
	ft_printf("\t-d N\t: Dumps memory after N cycles then exits\n");
	ft_printf("\t-v N\t: Verbosity levels, can be added together to enable \
several\n");
	ft_printf("\t\t- 0 : Show only essentials\n");
	ft_printf("\t\t- 1 : Show lives\n");
	ft_printf("\t\t- 2 : Show cycles\n");
	ft_printf("\t\t- 4 : Show operations\n");
	ft_printf("\t\t- 8 : Show deaths\n");
	ft_printf("\t\t- 16 : Show PC movements (Except for jumps)\n");
	return (0);
}

int main(int ac, char **av)
{
	t_vm		vm;
	char		ret;
	t_player	*winner;
	WINDOW		*windows[4];
	int entry;

	entry = 0;
	ret = 1;
	ft_memset(&vm, 0, sizeof(t_vm));
	if (ac < 2)
		return (print_usage());
	av++;
	vm.dumps = -1;
	av = vm_parse_line_command(av, &vm);
	(vm.vis == 1) ? init_windows(windows) : 1;
	vm_init(&vm);
	vm_fill_memory_vm(&vm);
	vm_introduce_contestants(&vm);
	while (ret == 1)
	{
		(ret == 1 && vm.pause != 1) ? (ret = vm_do_one_cycle(&vm)) : 1;
		(vm.vis == 1) ? display_all_windows(&vm, windows, ret) : 1;
	}
	if ((winner = vm_get_player(&vm, vm.last_live_player_no)))
		ft_printf("Contestant %d, \"%s\", has won !\n", winner->number,
		winner->name);
	else
		ft_printf("No player has won because no live was well performed\n");
	(vm.vis == 1) ? endwin() : 1;
	vm_delete_data(&vm);
	return (0);
}
