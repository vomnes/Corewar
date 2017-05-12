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

	ft_memset(&vm, 0, sizeof(t_vm));
	if (ac < 2)
		return (print_usage());
	av++;
	vm.dumps = -1;
	av = vm_parse_line_command(av, &vm);
	vm_init(&vm);
	vm_fill_memory_vm(&vm);

	ret = 1;
	while (ret == 1)
	{
		ret = vm_do_one_cycle(&vm);
		usleep(50000);
		ft_putstr("\033[H\033[2J");
		print_memory_dump(vm);
	}
//	print_memory_dump(vm);
//	vm_print_process(vm_get_process(&vm, 1));
	if ((winner = vm_get_player(&vm, vm.last_live_player_no)))
		ft_printf("le joueur %d(%s) a gagne\n", winner->number, winner->name);
	else
		ft_printf("Aucun joueur n'a gagne\n");

	// DELETE DATA
	return (0);
}
