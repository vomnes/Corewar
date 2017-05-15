#include "vm.h"

void		vm_sub(t_process *process, t_vm *vm)
{
	int	pc;
	int	sub1;
	int	sub2;
	int	diff;

	pc = vm_read_register(process->pc);
	process->carry = 0;
	if (vm_check_parameter_types(process->instruction) &&
		vm_get_parameters(process, vm) &&
		vm_valid_registers(process->instruction))
	{
		sub1 = vm_read_register(
			process->registers[process->instruction.params[0].uch]);
		sub2 = vm_read_register(
			process->registers[process->instruction.params[1].uch]);
		if ((diff = sub1 - sub2) == 0)
			process->carry = 1;
		vm_store_in_register(
			&process->registers[process->instruction.params[2].uch], diff);
		if (vm_verbose_operations(vm))
			ft_printf("P    %d | sub r%hhd r%hhd r%hhd\n", process->no,
			process->instruction.params[0].uch, process->
			instruction.params[1].uch, process->instruction.params[2].uch);
	}
	vm_advance_pc(process,vm);
}


/*
static void	sub_registers(t_process *process, t_vm *vm, int pc)
{
	int			first_param;
	int			second_param;
	int			third_param;

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
	vm_advance_pc(process, vm);
}
*/
