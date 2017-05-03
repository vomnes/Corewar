/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:11:27 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/03 19:04:36 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include "../../libft/includes/libft.h"
# include "../../libft/includes/libftprintf.h"
# include "../../libft/includes/get_next_line.h"
# include "../../shared_files/op.h"


typedef struct              s_instructions
{
    unsigned int            num_line;
    char                    *line_label;
    char                    is_label;
    char                    *label_name;
    char                    *line_opcode;
    char                    *line_args;
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

// t_operation

// t_arg arg1;
// t_arg arg2;
// t_arg arg3;
// char* output_bytes

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
int parse_name_comment(t_parsing *parsing);
int parse_labels(t_parsing *parsing);

int generate_binary_code(t_data *data);

void write_header(int fd, header_t header);

#endif
