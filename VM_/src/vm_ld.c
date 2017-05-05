#include "vm.h"

int					move_pc(t_process *process, int pc)
{
	int				count;

	count = 2;
	if (process->instruction.first_type == T_DIR)
		count += 4;
	else if (process->instruction.first_type == T_IND)
		count += 2;
	else if (process->instruction.first_type == T_REG)
		count += 1;
	if (process->instruction.second_type == T_DIR)
		count += 4;
	else if (process->instruction.second_type == T_IND)
		count += 2;
	else if (process->instruction.second_type == T_REG)
		count += 1;
	if (process->instruction.third_type == T_DIR)
		count += 4;
	else if (process->instruction.third_type == T_IND)
		count += 2;
	else if (process->instruction.third_type == T_REG)
		count += 1;
	pc += count;
	return (pc);
}

void				get_parameters(t_vm *vm, t_process *process, int pc, int i)
{
	int				first_param;
	int				second_param;
	int				tmp;

	tmp = 0;
	first_param = 0;
	second_param = 0;
	first_param = vm_read_memory_short(vm, pc + 2);
	second_param = vm->memory[MOD(pc + i)];
	if (second_param > 0 && second_param < REG_NUMBER)
	{
		tmp = vm_read_memory_int(vm, (pc + (first_param % IDX_MOD)));
		vm_store_in_register(&process->registers[second_param], tmp);
		process->carry = 1;
	}
	else
		process->carry = 0;
}

void				vm_ld(t_process *process, t_vm *vm)
{
	unsigned int	pc;

	pc = vm_read_register(process->pc);
	vm_decode_parameter_byte(process, vm);
	if (process->instruction.first_type == T_DIR)
		get_parameters(vm, process, pc, 6);
	else if (process->instruction.first_type == T_IND)
		get_parameters(vm, process, pc, 4);
	else
		process->carry = 0;
	vm_advance_pc(process);
}
