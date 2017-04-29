
#ifndef VM_H
# define VM_H

#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "op.h"

typedef	struct			s_player
{
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	unsigned int		size_player;
	int					number;
	int					nb_lives;
}						t_player;

typedef struct			s_process
{
	int					no;
	int					player_no;
	int					alive;
	unsigned char		registers[REG_NUMBER * REG_SIZE];
	unsigned char		pc[REG_SIZE];
	int					carry;
	struct s_process	*next;
	struct s_process	*prev;
}						t_process;

typedef struct			s_vm
{
	unsigned char		memory[MEM_SIZE];
	t_player			players[MAX_PLAYERS + 1];
	int					nb_players;
	t_process			*processes;
	int					cycle_nbr;
}						t_vm;

t_process				*vm_create_process(t_vm *vm);

void 					vm_error_exit(t_vm *vm, char *message);


#endif
