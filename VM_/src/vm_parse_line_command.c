#include "vm.h"

char		**vm_parse_line_command(char **av, int *dumps, t_vm *vm)
{
	int		count_champs;

	count_champs = 1;
	if (*av && ft_strcmp(*av, "-d") == 0)
	{
		*dumps = ft_atoi(av[1]);
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
