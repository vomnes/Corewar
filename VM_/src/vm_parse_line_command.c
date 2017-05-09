#include "vm.h"

char		**vm_parse_line_command(char **av, t_vm *vm)
{
	int		count_champs;
	int		tmp;

	count_champs = 1;
	tmp = 0;
	if (*av && ft_strcmp(*av, "-d") == 0)
	{
		if (av[1])
			tmp = ft_atoi(*av);
		if (tmp <= 0)
			vm_error_exit(vm, "Bad entry for option -d");
		av = av+ 2;
	}
	while (*av)             // faire avec un conteur, ac
	{
		av = vm_read_file_champ(av, vm, count_champs);
		count_champs++;
		++av;
	}
	return (av);
}
