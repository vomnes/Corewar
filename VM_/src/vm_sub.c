#include "vm.h"

static void	sub_registers(t_process *process, t_vm *vm, int pc)
{
	long long	first_param;
	long long	second_param;
	long long	third_param;

	first_param = vm->memory[MOD(pc + 2)];
	if (first_param > 0 && first_param <= REG_NUMBER)
	{
		first_param = vm_read_register(process->registers[first_param]);
		second_param = vm->memory[MOD(pc + 3)];
		if (second_param > 0 && second_param <= REG_NUMBER)
		{
			second_param = vm_read_register(process->registers[second_param]);
			third_param = vm->memory[MOD(pc + 4)];
			if (third_param > 0 && third_param <= REG_NUMBER)
			{
				vm_store_in_register(&process->registers[third_param],
						(first_param - second_param));
				process->carry = 1;
			}
		}
	}
}

void		vm_sub(t_process *process, t_vm *vm)
{
	int		pc;

	process->carry = 0;
	pc = vm_read_register(process->pc);
	if (vm_check_parameter_types(process->instruction) == 1)
		sub_registers(process, vm, pc);
	vm_advance_pc(process);
}
