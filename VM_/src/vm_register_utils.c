#include "vm.h"

long long		vm_read_register(unsigned char reg[REG_SIZE])
{
	long long	value;
	int	mask;
	int	i;

	value = 0;
	i = 0;
	while (i < REG_SIZE)
	{
		value = value << 8;
		mask = (int)(reg[i]);
		value = value | mask;
		i++;
	}
	return (value);
}

void	vm_store_in_register(unsigned char (*reg)[REG_SIZE], long long value)
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

void	vm_print_register(unsigned char reg[REG_SIZE])
{
	int i;
	int started;

	i = 0;
	started = 0;
	while (i < REG_SIZE)
	{
		if (started)
			ft_printf(" ");
		started = 1;
		ft_printf("%.2hhx", reg[i]);
		i++;
	}
}
