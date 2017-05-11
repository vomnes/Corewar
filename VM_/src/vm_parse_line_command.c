#include "vm.h"

char		**vm_parse_line_command(char **av, t_vm *vm)
{
	static int	count_champs = 1;
	int			tmp;

	if (*av && ft_strcmp(*av, "-dump") == 0)
	{
		if (av[1] && ft_atoi_error(av[1], &tmp) && tmp >= 0)
			vm->dumps = tmp;
		else
			vm_error_exit(vm, "Bad entry for option -dump");
		av = av + 2;
	}
	else if (*av && ft_strcmp(*av, "-vis") == 0)
	{
		vm->vis = 1;
		av++;
	}
	else if (*av)
	{
		av = vm_read_file_champ(av, vm, count_champs);
		count_champs++;
		++av;
	}
	else
		return (av);
	return (vm_parse_line_command(av, vm));
}
