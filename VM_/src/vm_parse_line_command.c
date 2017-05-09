#include "vm.h"

char		**vm_parse_line_command(char **av, t_vm *vm)
{
	int		count_champs;
	int		tmp;

	count_champs = 1;
	tmp = 0;
	if (*av && ft_strcmp(*av, "-dump") == 0)
	{
		if (av[1])
			tmp = ft_atoi(av[1]);
		if (tmp <= 0)
			vm_error_exit(vm, "Bad entry for option -d");
		vm->dumps = tmp;
		av = av + 2;
	}
	while (*av)
	{
		av = vm_read_file_champ(av, vm, count_champs);
		count_champs++;
		++av;
	}
	return (av);
}
