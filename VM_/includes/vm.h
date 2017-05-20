/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:03:50 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/20 14:02:59 by pdady            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <fcntl.h>
# include <stdio.h>
# include <curses.h>
# include "libft.h"
# include "op.h"

# define MOD(x) ((x) < 0 ? (MEM_SIZE + (x) % MEM_SIZE) : ((x) % MEM_SIZE))

extern t_op					g_op_tab[17];
typedef struct s_process	t_process;

typedef	struct			s_player
{
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	unsigned char		memory[CHAMP_MAX_SIZE];
	unsigned int		size_player;
	int					number;
	int					nb_alive_processes;
	int					cycle_of_last_live;
}						t_player;

typedef struct			s_cell
{
	int					player_no;
	int					present;
	int					recent;
	int					live;
	int					count;
}						t_cell;

typedef struct			s_vm
{
	unsigned char		memory[MEM_SIZE];
	t_cell				cells[MEM_SIZE];
	t_player			players[MAX_PLAYERS + 1];
	int					nb_players;
	t_process			*processes;
	t_process			*last_process;
	char				*heart[16];
	int					nb_processes;
	int					nb_alive_processes;
	int					lives_since_last_check;
	int					check_count;
	int					last_live_player_no;
	int					dumps;
	int					vis;
	int					verbose;
	int					aff;
	int					cycle_nbr;
	int					cycle_to_die;
	int					cycles_since_last_check;
	int					speed;
	int					pause;
}						t_vm;

typedef union			u_parameter
{
	unsigned char		uch;
	int					in;
	short				sh;
}						t_parameter;

typedef struct			s_instruction
{
	unsigned char		opcode;
	void				(*op)(t_process *, t_vm *);
	unsigned int		cycles_to_execution;
	t_arg_type			first_type;
	t_arg_type			second_type;
	t_arg_type			third_type;
	t_arg_type			args[MAX_ARGS_NUMBER];
	t_parameter			params[MAX_ARGS_NUMBER];
}						t_instruction;

struct					s_process
{
	int					no;
	int					player_no;
	int					nb_lives;
	int					last_live_cycle;
	int					alive;
	unsigned char		registers[REG_NUMBER + 1][REG_SIZE];
	int					pc;
	int					carry;
	t_instruction		instruction;
	struct s_process	*next;
	struct s_process	*prev;
};

int						check_entry_keys(t_vm *vm);

void					init_windows(WINDOW **window);
void					display_all_windows(t_vm *vm, WINDOW *window[4],
						char ret);
void					vis_print_memory(t_vm *vm, WINDOW *window);
void					vis_print_winner(t_vm *vm, WINDOW *window);
void					vis_print_info(t_vm *vm, WINDOW *window);
void					vis_print_skull(WINDOW *window, int pos);
void					vis_print_cup(WINDOW *window, int pos);

void					vm_init(t_vm *vm);
void					vm_introduce_contestants(t_vm *vm);

int						vm_verbose_lives(t_vm *vm);
int						vm_verbose_cycles(t_vm *vm);
int						vm_verbose_operations(t_vm *vm);
int						vm_verbose_deaths(t_vm *vm);
int						vm_verbose_pc(t_vm *vm);

void					vm_dump_if_necessary(t_vm *vm);

t_process				*vm_create_process(t_vm *vm);
t_process				*vm_delete_process(t_process *process, t_vm *vm);
void					vm_copy_process(t_process *parent, t_process *child,
						t_vm *vm);
t_process				*vm_get_process(t_vm *vm, int no);
void					vm_print_process(t_process *process);
int						vm_advance_pc(t_process *process, t_vm *vm);
int						vm_do_one_cycle(t_vm *vm);

void					vm_decode_parameter_byte(t_process *process, t_vm *vm);
int						vm_check_parameter_types(t_instruction instruction);
int						vm_get_parameters_xorand(t_process *process, t_vm *vm,
						char type, int *pc);
int						vm_get_parameters(t_process *process, t_vm *vm);
int						vm_param_to_int_idx(t_process *process, t_vm *vm,
						int i);
int						vm_param_to_int_no_idx(t_process *process, t_vm *vm,
						int i);

unsigned int			vm_n_bytes_to_uint(unsigned char *ptr, size_t n);
int						vm_read_memory_int(t_vm *vm, int index);
short					vm_read_memory_short(t_vm *vm, int index);
void					vm_store_in_memory_int(t_vm *vm, int index, int value);
void					vm_store_in_memory_short(t_vm *vm, int index,
						short value);
long long				vm_decode_index(t_vm *vm, t_process *process, int head);

int						vm_read_register(unsigned char reg[REG_SIZE]);
void					vm_store_in_register(unsigned char (*reg)[REG_SIZE],
						int value);
void					vm_print_register(unsigned char reg[REG_SIZE]);
int						vm_valid_registers(t_instruction instruction);

t_player				*vm_get_player(t_vm *vm, int player_nb);

void					vm_error_exit(t_vm *vm, char *message);
void					vm_delete_data(t_vm *vm);

void					vm_parse_header(size_t size, unsigned char buf[size], \
						t_vm *vm, int nb);
void					vm_fill_memory_vm(t_vm *vm);
char					**vm_read_file_champ(char **av, t_vm *vm, int n_player);
char					**vm_parse_line_command(char **av, t_vm *vm);

void					vm_fill_cells(t_vm *vm, int pos, int player_no);
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
