#include "vm.h"


static char **handle_dumps(char **av, t_vm *vm)
{
	int tmp;

	if (*av && ft_strcmp(*av, "-dump") == 0)
	{
		if (av[1] && ft_atoi_error(av[1], &tmp) && tmp >= 0)
			vm->dumps = tmp;
		else
			vm_error_exit(vm, "Bad entry for option -dump");
		return (av + 2);
	}
	return (NULL);
}

static char **handle_verbose(char **av, t_vm *vm)
{
	int	tmp;

	if (*av && ft_strcmp(*av, "-v") == 0)
	{
		if (av[1] && ft_atoi_error(av[1], &tmp) && tmp >= 0 && tmp <= 31)
			vm->verbose = tmp;
		else
			vm_error_exit(vm, "Bad entry for option -v");
		return (av + 2);
	}
	return (NULL);
}

char		**vm_parse_line_command(char **av, t_vm *vm)
{
	static int	count_champs = 1;
	char		**ret;

	if ((ret = handle_dumps(av, vm)))
		av = ret;
	else if ((ret = handle_verbose(av, vm)))
		av = ret;
	else if (*av && ft_strcmp(*av, "-vis") == 0)
	{
		vm->vis = 1;
		av++;
	}
	else if (*av && ft_strcmp(*av, "-a") == 0)
	{
		vm->aff = 1;
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
