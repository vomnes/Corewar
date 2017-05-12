#include "vm.h"

int			print_usage(void)
{
	ft_printf("Usage: ./corewar ...\n");
	return (0);
}

int main(int ac, char **av)
{
	t_vm		vm;
	int			ret;
	t_player	*winner;
	WINDOW *window;

	window = 0;
	ft_memset(&vm, 0, sizeof(t_vm));
	if (ac < 2)
		return (print_usage());
	av++;
	av = vm_parse_line_command(av, &vm);
	(vm.vis == 1) ? init_windows(&window) : 1;
	vm_init(&vm);
	vm_fill_memory_vm(&vm);

	ret = 1;
	while (ret == 1)
	{
		ret = vm_do_one_cycle(&vm);
		(vm.vis == 1) ? display_all_windows(vm, window) : 1;
	}
//	vm_print_process(vm_get_process(&vm, 1));
	if ((winner = vm_get_player(&vm, vm.last_live_player_no)))
		ft_printf("le joueur %d(%s) a gagne\n", winner->number, winner->name);
	else
		ft_printf("Aucun joueur n'a gagne\n");

	// DELETE DATA
	(vm.vis == 1) ? endwin() : 1;
	return (0);
}
