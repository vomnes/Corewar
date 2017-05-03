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
	else
		*type = T_LAB;
}

void			vm_decode_parameter_byte(t_process *process, t_vm *vm)
{
	unsigned char	byte;

	byte = vm->memory[MOD(vm_read_from_register(process->pc) + 1)];
	vm_decode_two_bits(byte, &process->instruction.first_type);
	byte = byte << 2;
	vm_decode_two_bits(byte, &process->instruction.second_type);
	byte = byte << 2;
	vm_decode_two_bits(byte, &process->instruction.third_type);
}
