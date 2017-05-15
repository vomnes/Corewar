#include "vm.h"

void	vm_zjmp(t_process *process, t_vm *vm)
{
	short	indirection;
	int	pc;

	pc = vm_read_register(process->pc);
	process->instruction.args[0] = T_DIR;
	vm_get_parameters(process, vm);
	indirection = vm_read_memory_short(vm, pc + 1);
	if (process->carry == 1)
	{
		vm_store_in_register(&process->pc, MOD(pc + indirection % IDX_MOD));
		if (vm_verbose_operations(vm))
			ft_printf("P    %d | zjmp %hd OK\n", process->no, indirection);
	}
	else
	{
		if (vm_verbose_operations(vm))
			ft_printf("P    %d | zjmp %hd FAILED\n", process->no, indirection);
		vm_advance_pc(process, vm);
	}
}
