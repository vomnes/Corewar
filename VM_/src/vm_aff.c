#include "vm.h"

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
	vm_advance_pc(process, vm);
}
