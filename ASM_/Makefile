NAME = asm

SRC =	./src/main.c \
			./src/write_header.c \
			./src/open_input.c \
			./src/create_binary_file.c \
			./src/generate_binary_code.c \
			./src/parsing.c \
			./src/ft_strtrim_comment.c \
			./src/parse_name_comment.c \
			./src/parse_labels.c \
			./src/add_new_instruction.c \
			./src/list_tools.c \
			./src/parse_opcode.c \
			./src/op.c \
			./src/parse_args.c \
			./src/add_arg.c \
			./src/get_args.c \
			./src/ft_isnumber_syntax.c \
			./src/arg_dir_ind_parse.c \
			./src/validate_arguments.c \
			./src/get_opcode.c \
			./src/create_binary_file.c

OBJ =	./obj/main.o \
			./obj/write_header.o \
			./obj/open_input.o \
			./obj/create_binary_file.o \
			./obj/generate_binary_code.o \
			./obj/parsing.o \
			./obj/ft_strtrim_comment.o \
			./obj/parse_name_comment.o \
			./obj/parse_labels.o \
			./obj/add_new_instruction.o \
			./obj/list_tools.o \
			./obj/parse_opcode.o \
			./obj/op.o \
			./obj/parse_args.o \
			./obj/add_arg.o \
			./obj/get_args.o \
			./obj/ft_isnumber_syntax.o \
			./obj/arg_dir_ind_parse.o \
			./obj/validate_arguments.o \
			./obj/get_opcode.o \
			./obj/create_index_bit.o

MAKE = make

GCC = gcc
FLAGS = -g -Wall -Werror -Wextra

INC = ./includes
LIB = ../libft
OBJ_PATH = ./obj

.PHONY: clean fclean all re lib

all: lib $(NAME)

$(NAME): $(OBJ) ok
				@$(GCC) $(FLAGS) -o $(NAME) $(OBJ) -I $(INC) -L $(LIB) -lft
				@echo "> \\033[4;m$(NAME)\\033[0m  :  [\\033[38;5;214mOK\\033[0m]"

ok :
			@echo -n \

$(OBJ): ./obj/%.o : ./src/%.c
				@mkdir $(OBJ_PATH) 2> /dev/null || true
				@echo "$(NAME) >>> Add/Update $^"
	    	@$(GCC) $(FLAGS) -c -I $(INC) $< -o $@ -I $(INC)

lib:
				@$(MAKE) -C $(LIB)

clean:
				@echo Clean objects $(NAME)
				@rm -rf $(OBJ)
				@rmdir obj 2> /dev/null || true
				@$(MAKE) -C $(LIB) clean

fclean: clean
				@$(MAKE) -C $(LIB) fclean
				@echo Clean $(NAME)
				@rm -rf $(NAME)
				@echo ======[Clean]======

re: fclean all
