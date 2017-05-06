#include "vm.h"

void		add_register(t_process *process, t_vm *vm, int pc)
{
	int		first_param;
	int		second_param;
	int		third_param;

	first_param = vm->memory[MOD(pc + 2)];
	if (first_param > 0 && first_param < REG_NUMBER)
	{
		first_param = vm_read_register(process->registers[first_param]);
		second_param = vm->memory[MOD(pc + 3)];
		if (second_param > 0 && second_param < REG_NUMBER)
		{
			second_param = vm_read_register(process->registers[second_param]);
			third_param = vm->memory[MOD(pc + 4)];
			if (third_param > 0 && third_param < REG_NUMBER)
				vm_store_in_register(&process->registers[third_param],
						(first_param + second_param));
		}
	}
}

void		vm_add(t_process *process, t_vm *vm)
{
	int		pc;

	pc = vm_read_register(process->pc);
	vm_decode_parameter_byte(process, vm);
	if (process->instruction.first_type == T_REG &&
			process->instruction.second_type == T_REG &&
				process->instruction.third_type == T_REG)
		add_register(process, vm, pc);
	vm_advance_pc(process);
}
