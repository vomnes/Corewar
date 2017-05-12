#include "vm.h"

unsigned int	vm_n_bytes_to_uint(unsigned char *ptr, size_t n)
{
	unsigned int	value;
	unsigned int	mask;

	value = 0;
	if (n > 4)
		ft_dprintf(2, "Error: trying to store %lu bytes in an int\n", n);
	while (n > 0)
	{
		value = value << 8;
		mask = (unsigned int)(*ptr);
		value = value | mask;
		ptr++;
		n--;
	}
	return (value);
}

/*
**	Reads 4 bytes of memory and returns it as a signed int.
**	Handles circular memory
*/

int				vm_read_memory_int(t_vm *vm, int index)
{
	int	value;
	int mask;
	int	i;

	value = 0;
	i = 0;
	while (i < 4)
	{
		index = MOD(index);
		value = value << 8;
		mask = (int)(vm->memory[index]);
		value = value | mask;
		index++;
		i++;
	}
	return (value);
}


/*
**	Reads 2 bytes of memory and returns it as a signed short.
**	Handles circular memory
*/

short			vm_read_memory_short(t_vm *vm, int index)
{
	short	value;
	short	mask;
	int		i;

	value = 0;
	i = 0;
	while (i < 2)
	{
		index = MOD(index);
		value = value << 8;
		mask = (short)(vm->memory[index]);
		value = value | mask;
		index++;
		i++;
	}
	return (value);
}

/*
**	Takes an int as an input and writes its 4 bytes in memory, starting
**	at the specified index.
**	Handles circular memory.
*/

void			vm_store_in_memory_int(t_vm *vm, int index, int value)
{
	int	i;

	i = 3;
	while (i >= 0)
	{
		index = MOD(index);
		vm->memory[index] = (unsigned char)(value >> (8 * i));
		index++;
		i--;
	}
}

/*
**	Takes an short as an input and writes its 2 bytes in memory, starting
**	at the specified index.
**	Handles circular memory.
*/

void			vm_store_in_memory_short(t_vm *vm, int index, short value)
{
	int	i;

	i = 1;
	while (i >= 0)
	{
		index = MOD(index);
		vm->memory[index] = (unsigned char)(value >> (8 * i));
		index++;
		i--;
	}
}
