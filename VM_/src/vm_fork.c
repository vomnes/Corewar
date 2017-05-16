#include "vm.h"

void	vm_fork(t_process *process, t_vm *vm)
{
	int			pc;
	short		indirection;
	t_process	*duplicate;

	process->instruction.first_type = T_DIR;
	process->instruction.args[0] = T_DIR;
//	pc = vm_read_register(process->pc);
	pc = process->pc;
	duplicate = vm_create_process(vm);
	vm_copy_process(process, duplicate, vm);
	indirection = vm_read_memory_short(vm, pc + 1);
	if (vm_verbose_operations(vm))
		ft_printf("P%5d | fork %d (%d)\n", process->no, indirection,
		pc + indirection % IDX_MOD);
	vm_advance_pc(process, vm);
//	vm_store_in_register(&duplicate->pc, MOD(pc + indirection % IDX_MOD));
	duplicate->pc = MOD(pc + indirection % IDX_MOD);
	vm->cells[MOD(pc + indirection % IDX_MOD)].present = process->player_no;
}
