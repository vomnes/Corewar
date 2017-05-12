
#ifndef VM_H
# define VM_H

# include <fcntl.h>
# include <stdio.h>
# include <curses.h>
# include "libft.h"
# include "op.h"

# define MOD(x) (x % MEM_SIZE)

extern t_op					g_op_tab[17];
typedef struct s_process	t_process;

typedef	struct			s_player
{
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	unsigned char		memory[CHAMP_MAX_SIZE];
	unsigned int		size_player;
	int					number;
}						t_player;

typedef struct			s_live
{
	int					player_no;
	struct s_live		*next;
}						t_live;

typedef struct			s_cell
{
	int					player_no;
	int					present;
	int					recent;
	int					live;
}						t_cell;

typedef struct			s_vm
{
	unsigned char		memory[MEM_SIZE];
	t_player			players[MAX_PLAYERS + 1];
	int					nb_players;
	t_process			*processes;
	int					nb_lives_since_last_check;
	int					last_live_player_no;
	int					dumps;
	int					vis;
	int					verbose;
	int					cycle_nbr;
	int					cycle_to_die;
	int					speed;
}						t_vm;

typedef struct			s_instruction
{
	unsigned char		opcode;
	void				(*op)(t_process *, t_vm *);
	unsigned int		cycles_to_execution;
	t_arg_type			first_type;
	t_arg_type			second_type;
	t_arg_type			third_type;
	t_arg_type			args[MAX_ARGS_NUMBER];
}						t_instruction;

struct					s_process
{
	int					no;
	int					player_no;
	int					nb_lives;
	int					alive;
	unsigned char		registers[REG_NUMBER + 1][REG_SIZE];
	unsigned char		pc[REG_SIZE];
	int					carry;
	t_instruction		instruction;
	struct s_process	*next;
	struct s_process	*prev;
};

void					init_windows(WINDOW **window);
void					display_all_windows(t_vm vm, WINDOW *window);

void					vm_init(t_vm *vm);
void					vm_introduce_contestants(t_vm *vm);

int						vm_verbose_lives(t_vm *vm);
int						vm_verbose_cycles(t_vm *vm);
int						vm_verbose_operations(t_vm *vm);
int						vm_verbose_deaths(t_vm *vm);
int						vm_verbose_pc(t_vm *vm);

void					vm_dump_if_necessary(t_vm *vm);

t_process				*vm_create_process(t_vm *vm);
void 					vm_copy_process(t_process *parent, t_process *child);
t_process				*vm_get_process(t_vm *vm, int no);
void					vm_print_process(t_process *process);
int						vm_advance_pc(t_process *process);
int						vm_do_one_cycle(t_vm *vm);

void					vm_decode_parameter_byte(t_process *process, t_vm *vm);
int						vm_check_parameter_types(t_instruction instruction);
long long				vm_get_parameters_xorand(t_process *process, t_vm *vm,
						char type, int *pc);

unsigned int			vm_n_bytes_to_uint(unsigned char *ptr, size_t n);
long long 				vm_read_memory_int(t_vm *vm, int index, int size);
short					vm_read_memory_short(t_vm *vm, int index);
void					vm_store_in_memory_int(t_vm *vm, int index, long long
																		value);
void					vm_store_in_memory_short(t_vm *vm, int index,
						short value);
long long				vm_decode_index(t_vm *vm, t_process *process, int head);

long long				vm_read_register(unsigned char reg[REG_SIZE]);
void					vm_store_in_register(unsigned char (*reg)[REG_SIZE],
						long long value);
void					vm_print_register(unsigned char reg[REG_SIZE]);


t_player 				*vm_get_player(t_vm *vm, int player_nb);

void					vm_error_exit(t_vm *vm, char *message);

void					vm_parse_header(size_t size, unsigned char buf[size], \
						t_vm *vm, int nb);
void					vm_fill_memory_vm(t_vm *vm);
char					**vm_read_file_champ(char **av, t_vm *vm, int n_player);
char					**vm_parse_line_command(char **av, t_vm *vm);

void					print_memory_dump(t_vm vm);

t_instruction			vm_read_opcode(t_vm *vm, unsigned int pc);
void					vm_null_op(t_process *process, t_vm *vm);
void					vm_live(t_process *process, t_vm *vm);
void					vm_ld(t_process *process, t_vm *vm);
void					vm_st(t_process *process, t_vm *vm);
void					vm_add(t_process *process, t_vm *vm);
void					vm_sub(t_process *process, t_vm *vm);
void					vm_and(t_process *process, t_vm *vm);
void					vm_or(t_process *process, t_vm *vm);
void					vm_xor(t_process *process, t_vm *vm);
void					vm_zjmp(t_process *process, t_vm *vm);
void					vm_ldi(t_process *process, t_vm *vm);
void					vm_sti(t_process *process, t_vm *vm);
void					vm_fork(t_process *process, t_vm *vm);
void					vm_lld(t_process *process, t_vm *vm);
void					vm_lldi(t_process *process, t_vm *vm);
void					vm_lfork(t_process *process, t_vm *vm);
void					vm_aff(t_process *process, t_vm *vm);

t_instruction			vm_read_opcode(t_vm *vm, unsigned int pc);

#endif
