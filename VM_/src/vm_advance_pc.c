#include "vm.h"

int			vm_advance_pc(t_process *process)
{
	int				pc;
	int				i;

	pc = vm_read_register(process->pc) + 1;
	if (g_op_tab[process->instruction.opcode].param_byte)
		pc += 1;
	i = g_op_tab[process->instruction.opcode].nb_args - 1;
	while (i >= 0)
	{
		if (process->instruction.args[i] == T_DIR)
		{
			if (g_op_tab[process->instruction.opcode].has_index)
				pc += 2;
			else
				pc += 4;
		}
		else if (process->instruction.args[i] == T_IND)
			pc += 2;
		else if (process->instruction.args[i] == T_REG)
			pc += 1;
		i--;
	}
	pc = MOD(pc);
	vm_store_in_register(&process->pc, pc);
	return (pc);
}
