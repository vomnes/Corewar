#include "vm.h"

static void	advance_pc(t_process *process, int pc)
{
	if (process->instruction.first_type == T_REG)
		vm_store_in_register(&process->pc, MOD(pc + 3));
	else if (process->instruction.first_type == T_DIR)
		vm_store_in_register(&process->pc, MOD(pc + 6));
	else if (process->instruction.first_type == T_IND)
		vm_store_in_register(&process->pc, MOD(pc + 4));
	else
		vm_store_in_register(&process->pc, MOD(pc + 2));
}


void		vm_aff(t_process *process, t_vm *vm)
{
	int				character;
	unsigned char	reg_number;
	int				pc;

	pc = vm_read_register(process->pc);
	if (process->instruction.first_type == T_REG)
	{
		reg_number = vm->memory[MOD(pc + 2)];
		if (reg_number > 0 && reg_number <= REG_NUMBER)
		{
			character = vm_read_register(process->registers[reg_number]);
			character = character % 256;
			ft_printf("%c", (char)character);
		}
	}
	advance_pc(process, pc);
}
