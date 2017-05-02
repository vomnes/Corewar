# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 15:21:01 by atrudel           #+#    #+#              #
#    Updated: 2017/05/02 15:34:20 by pdady            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

LIB_PATH = ../libft
OBJ_PATH = ./obj
SRC_PATH = ./src
INC_PATH = ./includes

SRC_FILES =	corewar.c \
			vm_process.c \
			vm_error.c \
			vm_utils.c \
			vm_parse_header.c\
			vm_fill_memory_vm.c\
			vm_read_file_champ.c\
			vm_parse_line_command.c

INC_FILES = vm.h

SRC = $(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_FILES:.c=.o)) \
# Ajouter op.o

INC = $(addprefix $(INC_PATH)/, $(INC_FILES))

FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME): $(OBJ) $(INC) $(LIB_PATH)/libft.a $(LIB_PATH)/includes/libft.h
	gcc -o $(NAME) $(OBJ) $(FLAGS) -L $(LIB_PATH) -lft -I . -I $(INC_PATH) -I $(LIB_PATH)/includes -I ../shared_files

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC) $(LIB_PATH)/includes/libft.h
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc -o $@ -c $< $(FLAGS) -I . -I $(INC_PATH) -I $(LIB_PATH)/includes -I ../shared_files

$(LIB_PATH)/libft.a: $(LIB_PATH)/Makefile $(LIB_PATH)/includes/libft.h
	@make -C $(LIB_PATH)
	@echo "libft created"

clean:
	rm -Rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC) $(INC)

.PHONY: clean fclean re norme
