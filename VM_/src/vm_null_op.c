#include "vm.h"

void	vm_null_op(t_process *process, t_vm *vm)
{
	int	pc1;
	int	pc2;

//	pc1 = vm_read_register(process->pc);
	pc1 = process->pc;
	pc2 = MOD(pc1 + 1);
	//vm_store_in_register(&process->pc, pc2);
	process->pc = pc2;
	vm->cells[pc1].present = 0;
	vm->cells[pc2].present = process->player_no;
}
