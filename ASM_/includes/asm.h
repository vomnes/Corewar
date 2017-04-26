#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include "../../libft/includes/libft.h"
# include "../../libft/includes/libftprintf.h"
# include "op.h"

typedef struct s_input
{
  int         fd;
  char        file_name[129];
}             t_input;

typedef struct  s_data
{
  t_input       input;
  header_t      header;
}               t_data;

int open_input(int argc, char **argv, t_input *input_data);
int create_binary_file(t_input input);
void write_header(int fd, header_t header);

#endif
