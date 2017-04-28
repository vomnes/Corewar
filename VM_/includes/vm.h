
#ifndef VM_H
# define VM_H

#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "../../shared_files/op.h"

typedef	struct		s_player
{
	char			*name;
	int				nb_lives;
}					t_player;

typedef struct		s_process
{
	int				no;
	int				player_no;
	int				alive;
	unsigned char	*registers;
	unsigned char	*PC;
	int				carry;
}					t_process;

typedef struct		s_vm
{
	unsigned char	*memory;
	t_player		players[MAX_PLAYERS];
	int				nb_players;
	t_list			*processes;
	int				cycle_nbr;
}					t_vm;

void 				vm_error_exit(t_vm *vm, char *message);


#endif
