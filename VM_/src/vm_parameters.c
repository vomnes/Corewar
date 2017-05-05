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

	byte = vm->memory[MOD(vm_read_register(process->pc) + 1)];
	vm_decode_two_bits(byte, &process->instruction.first_type);
	process->instruction.args[0] = process->instruction.first_type;
	byte = byte << 2;
	vm_decode_two_bits(byte, &process->instruction.second_type);
	process->instruction.args[1] = process->instruction.second_type;
	byte = byte << 2;
	vm_decode_two_bits(byte, &process->instruction.third_type);
	process->instruction.args[2] = process->instruction.third_type;
}

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
