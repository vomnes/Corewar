#include "vm.h"

void		vm_aff(t_process *process, t_vm *vm)
{
	int				character;

	if (vm_check_parameter_types(process->instruction) &&
		vm_get_parameters(process, vm) &&
		vm_valid_registers(process->instruction))
	{
		character = vm_read_register(
			process->registers[process->instruction.params[0].uch]);
		character = character % 256;
		if (vm->aff)
			ft_printf("Aff: %c\n", (char)character);
	}
	vm_advance_pc(process, vm);
}
