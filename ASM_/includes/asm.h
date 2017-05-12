/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:11:27 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/12 15:23:32 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include "../../libft/includes/libft.h"
# include "../../libft/includes/libftprintf.h"
# include "../../libft/includes/get_next_line.h"
# include "../../shared_files/op.h"

# define FILE argc - 1
# define OPTION argc - 2

# define REG_OCTET 1
# define IND_OCTET 2
# define DIR_OCTET 4
# define DIR_OCTET_INDEX 2

typedef	struct				s_args
{
	char					*content;
	char					type;
	char					t_arg;
	int						value;
	char					*label;
	struct s_args			*next;
}							t_args;

typedef struct				s_instructions
{
	unsigned int			num_line;
	char					*line_label;
	char					is_label;
	char					*label_name;
	char					*line_opcode;
	signed char				opcode;
	char					*line_args;
	int						param_byte;
	int						index_octet;
	t_args					*arg;
	struct s_instructions	*next;
}							t_instructions;

typedef struct				s_parsing
{
	unsigned int			line_nb;
	char					*clean_line;
	char					*label_name;
	char					*line_label;
	char					*line_opcode;
	char					*line_args;
	t_instructions			*lst;
	char					name_stocked;
	char					comment_stocked;
	char					name_comment_stocked;
}							t_parsing;

typedef struct				s_input
{
	int						fd;
	char					file_name[128 + 1];
}							t_input;

typedef struct				s_output
{
	int						fd;
}							t_output;

typedef struct				s_data
{
	header_t				header;
	t_input					input;
	t_output				binary_file;
	t_parsing				parsing;
}							t_data;

extern	t_op				g_op_tab[17];

int							open_input(int argc, char **argv, \
t_input *input_data);
int							create_binary_file(t_input input);

int							parsing_input(t_data *data);
void						init_struct_parsing(t_parsing *parsing);
char						*ft_strtrim_comment(char *s, char comment_char);
int							ft_isprint_nospace(int c);
void						check_header_content(const char *cmd_string, \
unsigned int content_len, t_parsing *parsing, header_t *header);
int							parse_name_comment(t_parsing *parsing, \
header_t *header);
int							parse_labels(t_parsing *parsing);
int							get_opcode(char *to_analyse, char **opcode_name);
int							parse_opcode(t_instructions **lst);
int							get_args(t_instructions **lst);
int							arg_dir_ind_parse(t_args *current, \
char num_arg, int num_line, t_instructions *check_label);
int							parse_args(t_instructions **lst);
int							validate_arguments(t_instructions **lst);

int							ft_isnumber_syntax(char *str, char sign);
int							add_new_instruction(t_instructions **lst_head, \
t_parsing *collect);
int							add_arg(t_args **lst_head, char *content);

int							create_param_byte(t_instructions **lst);
int							set_label_value(t_instructions **lst);
int							get_prog_data(t_instructions **lst, \
header_t *header);
int							program_data(t_data *data);

void						ft_write_byte(int fd, unsigned int value, \
char nb_octet);
void						write_header(int fd, header_t header);
int							write_binary(t_instructions **lst, \
t_output *binary_file);
int							generate_binary_code(t_data *data);

void						ft_display_hex_octet(unsigned long long int nb, \
int nb_octet);
void						details_compilation(t_instructions *lst, \
header_t header);

int							ft_exit_clean(t_instructions **lst, int type);

#endif
