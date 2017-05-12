#include "vm.h"

int		vm_verbose_lives(t_vm *vm)
{
	if (vm->verbose & 1)
		return (1);
	else
		return (0);
}

int		vm_verbose_cycles(t_vm *vm)
{
	if (vm->verbose & 2)
		return (1);
	else
		return (0);
}

int		vm_verbose_operations(t_vm *vm)
{
	if (vm->verbose & 4)
		return (1);
	else
		return (0);
}

int		vm_verbose_deaths(t_vm *vm)
{
	if (vm->verbose & 8)
		return (1);
	else
		return (0);
}

int		vm_verbose_pc(t_vm *vm)
{
	if (vm->verbose & 16)
		return (1);
	else
		return (0);
}
