/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_transform_instructions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 13:52:18 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/14 14:53:39 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse.h"

#define DIR_O_I DIR_OCTET_INDEX

static int	rev_byte_get_arg_type(unsigned int value, char byte[3])
{
	int		byte_offset;
	int		i;

	byte_offset = 6;
	i = 0;
	while (byte_offset >= 2)
	{
		byte[i] = (value >> byte_offset) & 3;
		byte_offset -= 2;
		i++;
	}
	return (i);
}

static int	rev_value_bytes(unsigned int memory[MEMORY_SIZE], char nb_octet, \
size_t *i)
{
	int		byte_offset;
	int		value;

	value = 0;
	byte_offset = 8 * (nb_octet - 1);
	while (byte_offset >= 0)
	{
		value = (memory[*i] << byte_offset) | value;
		byte_offset -= 8;
		(*i)++;
	}
	return (value);
}

static void	rev_process_with_multi_args(unsigned int memory[MEMORY_SIZE], \
size_t *i, short opcode)
{
	int		index;
	char	byte[3];

	rev_byte_get_arg_type(memory[*i], byte);
	(*i)++;
	index = 0;
	while (index < g_op_tab[opcode].nb_args)
	{
		if (byte[index] == REG_CODE)
			ft_printf("r%d", rev_value_bytes(memory, REG_OCTET, &(*i)));
		else if (byte[index] == IND_CODE)
			ft_printf("%d", rev_value_bytes(memory, IND_OCTET, &(*i)));
		else if (byte[index] == DIR_CODE)
		{
			if (g_op_tab[opcode].has_index == 0)
				ft_printf("%%%d", rev_value_bytes(memory, DIR_OCTET, &(*i)));
			else
				ft_printf("%%%d", rev_value_bytes(memory, DIR_O_I, &(*i)));
		}
		if (index == g_op_tab[opcode].nb_args - 1)
			ft_putchar('\n');
		else
			ft_putchar(',');
		index++;
	}
}

void		rev_transform_instructions(unsigned int memory[MEMORY_SIZE], \
size_t size_prog)
{
	size_t	i;
	short	opcode;

	i = 0;
	opcode = 0;
	while (i < size_prog)
	{
		if (i >= MEMORY_SIZE)
			ft_dprintf(2, "%s\n", "Not a valid file");
		opcode = memory[i];
		if (opcode > 16)
			opcode = 0;
		i++;
		if (g_op_tab[opcode].name)
			ft_printf("\t%s ", g_op_tab[opcode].name);
		if (g_op_tab[opcode].param_byte == 1)
			rev_process_with_multi_args(memory, &i, opcode);
		else
		{
			if (g_op_tab[opcode].has_index == 0)
				ft_printf("%%%d\n", rev_value_bytes(memory, DIR_OCTET, &i));
			else
				ft_printf("%%%d\n", rev_value_bytes(memory, DIR_O_I, &i));
		}
	}
}
