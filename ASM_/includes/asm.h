/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:11:27 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/09 12:14:51 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include "../../libft/includes/libft.h"
# include "../../libft/includes/libftprintf.h"
# include "../../libft/includes/get_next_line.h"
# include "../../shared_files/op.h"

extern t_op g_op_tab[17];

typedef struct              s_args
{
    char                    *content;
    char                    type;
    char                    t_arg;
    int                     value;
    char                    *label;
    struct s_args           *next;
}                           t_args;

typedef struct              s_instructions
{
    unsigned int            num_line;
    char                    *line_label;
    char                    is_label;
    char                    *label_name;
    char                    *line_opcode;
    signed char             opcode;
    char                    *line_args;
    int                     param_byte;
    int                     index_octet;
    t_args                  *arg;
    struct s_instructions   *next;
}                           t_instructions;

typedef struct      s_parsing
{
    unsigned int    line_nb;
    char            *clean_line;
    char            *label_name;
    char            *line_label; //clean_line
    char            *line_opcode; //input_line
    char            *line_args;
    t_instructions  *lst;
    char            name_stocked;
    char            comment_stocked;
    char            name_comment_stocked;
}                   t_parsing;

//t_label
// liste d'occurrences (numero du byte a modifier)
// position absolue

typedef struct s_input
{
  int         fd;
  char        file_name[128 + 1];
}             t_input;

typedef struct s_output
{
  int         fd;
}             t_output;

typedef struct  s_data
{
  header_t      header;
  t_input       input;
  t_output      binary_file;
  t_parsing     parsing;
}               t_data;

int open_input(int argc, char **argv, t_input *input_data);
int create_binary_file(t_input input);

int parsing_input(t_data *data);
char	*ft_strtrim_comment(char *s, char comment_char);
int		ft_isprint_nospace(int c);
void check_header_content(const char *cmd_string, unsigned int content_len,
t_parsing *parsing, header_t *header);
int parse_name_comment(t_parsing *parsing, header_t *header);
int parse_labels(t_parsing *parsing);
int get_opcode(char *to_analyse, char **opcode_name);
int parse_opcode(t_instructions **lst);
int get_args(t_instructions **lst);
int parse_args(t_instructions **lst);
int ft_isnumber_syntax(char *str, char sign);
int validate_arguments(t_instructions **lst);

int arg_dir_ind_parse(t_args *current, char num_arg, int num_line, \
t_instructions *check_label);

int				add_new_instruction(t_instructions **lst_head, \
t_parsing *collect);
int				add_arg(t_args **lst_head, char *content);

int get_prog_data(t_instructions **lst, header_t *header);
int set_label_value(t_instructions **lst);
int create_param_byte(t_instructions **lst);

int generate_binary_code(t_data *data);

void ft_write_byte(int fd, unsigned int value, char nb_octet);
void write_header(int fd, header_t header);

void print_instructions_list(t_instructions *lst);
void delete_lst_instructions(t_instructions *lst);
void print(t_args *lst);

#endif
