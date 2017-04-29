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
