#include "vm.h"

int			print_usage(void)
{
	ft_printf("Usage: ./corewar ...\n");
	return (0);
}

int main(int ac, char **av)
{
	t_vm	vm;

	ft_memset(&vm, 0, sizeof(t_vm));
	if (ac < 2)
		return (print_usage());
	av++;
	av = vm_parse_line_command(av, &vm);
	vm_init(&vm);
	vm_fill_memory_vm(&vm);

//	print_memory_dump(vm);
//	vm_print_process(vm_get_process(&vm, 1));

	return (0);
}
