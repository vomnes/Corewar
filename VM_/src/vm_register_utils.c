#include "vm.h"


// AJOUTER LES MOD(X)
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

unsigned int	vm_read_from_register(unsigned char reg[REG_SIZE])
{
	return (vm_n_bytes_to_uint((unsigned char *)reg, REG_SIZE));
}

void			vm_store_in_register(unsigned char (*reg)[REG_SIZE], int value)
{
	int				i;

	i = REG_SIZE - 1;
	while (i >= 0)
	{
		(*reg)[i] = (unsigned char)value;
		value = value >> 8;
		i--;
	}
}
