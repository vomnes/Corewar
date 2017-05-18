/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_parse_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:32:20 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 11:33:13 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				vm_pick_size_player(unsigned char *buf, t_player *player)
{
	player->size_player = vm_n_bytes_to_uint(buf, 4);
	if (player->size_player > CHAMP_MAX_SIZE)
	{
		ft_dprintf(2, "Error: champ %s has too large code \
(%d bytes > %d bytes)\n",
				player->name, player->size_player, CHAMP_MAX_SIZE);
		exit(-1);
	}
}

void				vm_check_exec_magic(unsigned char *buf)
{
	unsigned int	nb;

	nb = vm_n_bytes_to_uint(buf, 4);
	if (nb != COREWAR_EXEC_MAGIC)
	{
		ft_putendl_fd("Error: Not a .cor file", 2);
		exit(-1);
	}
}

void				vm_pick_info(size_t size, unsigned char buf[size], \
		t_player *player)
{
	size_t			i;
	size_t			j;

	i = 4;
	j = 0;
	vm_check_exec_magic(buf);
	while (i < size && i < PROG_NAME_LENGTH)
		player->name[j++] = buf[i++];
	vm_pick_size_player(&buf[i + 8], player);
	i += 12;
	j = 0;
	while (i < size)
		player->comment[j++] = buf[i++];
}

void				vm_parse_header(size_t size, unsigned char buf[size], \
		t_vm *vm, int nb)
{
	size_t			i;

	i = 1;
	if (nb > MAX_PLAYERS)
		vm_error_exit(vm, "Error: too many players");
	if (nb && vm->players[nb].number != 0)
	{
		ft_dprintf(2, "Error: Player number [%d] already taken, please\
choose one number for each players\n", nb);
		exit(-1);
	}
	vm->players[nb].number = nb;
	vm_pick_info(size, buf, &vm->players[nb]);
}
