
#ifndef VM_H
# define VM_H

# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "op.h"

# define MOD(x) (x % MEM_SIZE)

typedef struct s_process	t_process;

typedef	struct			s_player
{
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	unsigned char		memory[CHAMP_MAX_SIZE];
	unsigned int		size_player;
	int					number;
	int					nb_lives;
}						t_player;

typedef struct			s_vm
{
	unsigned char		memory[MEM_SIZE];
	t_player			players[MAX_PLAYERS + 1];
	int					nb_players;
	t_process			*processes;
	int					cycle_nbr;
}						t_vm;

typedef struct			s_instruction
{
	unsigned char		opcode;
	unsigned int		(*op)(t_process *, t_vm *);
	unsigned int		cycles_to_execution;
	t_arg_type			first_type;
	t_arg_type			second_type;
	t_arg_type			third_type;

}						t_instruction;

struct					s_process
{
	int					no;
	int					player_no;
	int					alive;
	unsigned char		registers[REG_NUMBER + 1][REG_SIZE];
	unsigned char		pc[REG_SIZE];
	int					carry;
	t_instruction		instruction;
	struct s_process	*next;
	struct s_process	*prev;
};

t_process				*vm_create_process(t_vm *vm);

void					vm_decode_parameter_byte(t_process *process, t_vm *vm);

unsigned int			vm_n_bytes_to_uint(unsigned char *ptr, size_t n);
unsigned int			vm_read_from_register(unsigned char reg[REG_SIZE]);
void					vm_store_in_register(unsigned char (*reg)[REG_SIZE],
						int value);

char 					*vm_get_player_name(t_vm *vm, int player_nb);

void					vm_error_exit(t_vm *vm, char *message);

#endif
