# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/18 11:15:05 by atrudel           #+#    #+#              #
#    Updated: 2017/05/23 12:00:27 by atrudel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = ../corewar

LIB_PATH = ../libft
OBJ_PATH = ./obj
OBJ_PATH_VIS = ./obj
SRC_PATH = ./src
INC_PATH = ./includes


SRC_FILES =	corewar.c \
			vm_init.c \
			vm_introduce_contestants.c \
			vm_verbose.c \
			vm_dump.c \
			vm_cycles.c \
			vm_process.c \
			vm_advance_pc.c \
			vm_parameters.c \
			vm_parameters2.c \
			vm_error.c \
			vm_utils.c \
			vm_delete_data.c \
			vm_register_utils.c \
			vm_player_utils.c \
			vm_memory_rw.c \
			vm_index.c \
			vm_parse_header.c \
			vm_fill_memory_vm.c \
			vm_read_file_champ.c \
			vm_parse_line_command.c \
			vm_opcode.c \
			vm_null_op.c \
			vm_live.c \
			vm_ld.c\
			vm_st.c \
			vm_add.c \
			vm_sub.c \
			vm_and.c \
			vm_or.c \
			vm_xor.c \
			vm_zjmp.c \
			vm_ldi.c \
			vm_sti.c \
			vm_fork.c \
			vm_lld.c \
			vm_lldi.c \
			vm_lfork.c \
			vm_aff.c \


VISU_FILE =	visu.c vis_print_memory.c vis_print_winner.c vis_print_info.c \
			vis_draw_utils.c

INC_FILES = vm.h

SRC = $(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_FILES:.c=.o))
OBJ_VIS = $(addprefix $(OBJ_PATH_VIS)/, $(VISU_FILE:.c=.o))

INC = $(addprefix $(INC_PATH)/, $(INC_FILES))

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ) ../shared_files/op.o $(INC) $(LIB_PATH)/libft.a $(LIB_PATH)/includes/libft.h $(OBJ_VIS)
	@gcc -o $(NAME) $(OBJ) ../shared_files/op.o $(OBJ_VIS) -lncurses $(FLAGS) -L $(LIB_PATH) -lft -I . -I $(INC_PATH) -I $(LIB_PATH)/includes -I ../shared_files
	@echo "> \\033[4;mcorewar\\033[0m  :  [\\033[38;5;214mOK\\033[0m]"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC) $(LIB_PATH)/includes/libft.h
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc -o $@ -c $< $(FLAGS) -I . -I $(INC_PATH) -I $(LIB_PATH)/includes -I ../shared_files
	@echo "corewar >>> Add/Update $<"

$(LIB_PATH)/libft.a: $(LIB_PATH)/Makefile $(LIB_PATH)/includes/libft.h
	@make -C $(LIB_PATH)
	@echo "libft created"

../shared_files/op.o: ../shared_files/op.c $(INC) $(LIB_PATH)/includes/libft.h
	@gcc -o $@ -c $< $(FLAGS) -I ../shared_files

$(OBJ_PATH_VIS)/%.o: ./src/$(VISU_FILE) $(INC) $(LIB_PATH)/includes/libft.h
	@gcc -o $@ -c $< $(FLAGS) -I $(INC_PATH) -I $(LIB_PATH)/includes -I ../shared_files/
	@echo "corewar >>> Add/Update $<"

clean:
	@echo Clean objects corewar
	@rm -Rf $(OBJ_PATH)
	@rm -f ../shared_files/op.o

fclean: clean
	@echo Clean corewar
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
