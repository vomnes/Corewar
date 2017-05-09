#include "vm.h"

int			print_usage(void)
{
	ft_printf("Usage: ./corewar ...\n");
	return (0);
}

int main(int ac, char **av)
{
	int		dumps;
	t_vm	vm;

	dumps = 0;
	ft_memset(&vm, 0, sizeof(t_vm));
	if (ac < 2)
		return (print_usage());
	av++;
	av = vm_parse_line_command(av, &dumps, &vm);
	vm_init(&vm);
	vm_fill_memory_vm(&vm);

	print_memory_dump(vm);
	vm_print_process(vm_get_process(&vm, 1));

	return (0);
}
