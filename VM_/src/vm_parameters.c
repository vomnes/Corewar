#include "vm.h"

static void		vm_decode_two_bits(unsigned char byte, t_arg_type *type)
{
	unsigned char mask_reg;
	unsigned char mask_dir;
	unsigned char mask_ind;

	mask_reg = 64;
	mask_dir = 128;
	mask_ind = 192;
	if ((byte & mask_ind) == mask_ind)
		*type = T_IND;
	else if ((byte & mask_reg) == mask_reg)
		*type = T_REG;
	else if ((byte & mask_dir) == mask_dir)
		*type = T_DIR;
}

void			vm_decode_parameter_byte(t_process *process, t_vm *vm)
{
	unsigned char	byte;

	byte = vm->memory[MOD(process->pc + 1)];
	//byte = vm->memory[MOD(vm_read_register(process->pc) + 1)];
	vm_decode_two_bits(byte, &process->instruction.first_type);
	process->instruction.args[0] = process->instruction.first_type;
	byte = byte << 2;
	vm_decode_two_bits(byte, &process->instruction.second_type);
	process->instruction.args[1] = process->instruction.second_type;
	byte = byte << 2;
	vm_decode_two_bits(byte, &process->instruction.third_type);
	process->instruction.args[2] = process->instruction.third_type;
}

/*
**	This function returns 1 if all parameters types correspond to the types
**	specified in op_tab. Returns 0 if at least one parameter type is incorrect.
*/

int				vm_check_parameter_types(t_instruction instruction)
{
	int		i;
	t_op	op;

	op = g_op_tab[instruction.opcode];
	i = 0;
	while (i < op.nb_args)
	{
		if ((instruction.args[i] & op.arg_types[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int			vm_get_one_parameter(t_process *process, t_vm *vm, int head,
					int i)
{
	if (process->instruction.args[i] == T_REG)
	{
		process->instruction.params[i].uch = vm->memory[head];
		return (head + 1);
	}
	else if (process->instruction.args[i] == T_DIR)
	{
		if (g_op_tab[process->instruction.opcode].has_index)
		{
			process->instruction.params[i].sh = vm_read_memory_short(vm, head);
			return (head + 2);
		}
		else
		{
			process->instruction.params[i].in = vm_read_memory_int(vm, head);
			return (head + 4);
		}
	}
	else if (process->instruction.args[i] == T_IND)
	{
		process->instruction.params[i].sh = vm_read_memory_short(vm, head);
		return (head + 2);
	}
	return (head);
}

int					vm_get_parameters(t_process *process, t_vm *vm)
{
	int	i;
	int head;

	//head = MOD(vm_read_register(process->pc) + 1);
	head = MOD(process->pc + 1);
	if (g_op_tab[process->instruction.opcode].param_byte)
		head = MOD(head + 1);
	i = 0;
	while (i < g_op_tab[process->instruction.opcode].nb_args)
	{
		head = MOD(vm_get_one_parameter(process, vm, head, i));
		i++;
	}
	return (1);
}
