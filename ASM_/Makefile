NAME = ../asm

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
			./src/parse_opcode.c \
			./src/op.c \
			./src/parse_args.c \
			./src/add_arg.c \
			./src/get_args.c \
			./src/ft_isnumber_syntax.c \
			./src/arg_dir_ind_parse.c \
			./src/validate_arguments.c \
			./src/get_opcode.c \
			./src/create_param_byte.c \
			./src/ft_write_byte.c \
			./src/check_header_content.c \
			./src/ft_isprint_nospace.c \
			./src/get_prog_data.c \
			./src/set_value.c \
			./src/write_binary.c \
			./src/ft_display_hex_octet.c \
			./src/details_compilation.c \
			./src/program_data.c \
			./src/init_struct_parsing.c \
			./src/ft_exit_clean.c \
			./src/rev_process_reverse_binary.c \
			./src/rev_transform_header.c \
			./src/rev_transform_instructions.c \
			./src/ft_is_label_chars.c \
			./src/eval_expr.c \
			./src/label_exist.c \
			./src/exit_free_expression_tab.c

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
			./obj/parse_opcode.o \
			./obj/op.o \
			./obj/parse_args.o \
			./obj/add_arg.o \
			./obj/get_args.o \
			./obj/ft_isnumber_syntax.o \
			./obj/arg_dir_ind_parse.o \
			./obj/validate_arguments.o \
			./obj/get_opcode.o \
			./obj/create_param_byte.o \
			./obj/ft_write_byte.o \
			./obj/check_header_content.o \
			./obj/ft_isprint_nospace.o \
			./obj/get_prog_data.o \
			./obj/set_value.o \
			./obj/write_binary.o \
			./obj/ft_display_hex_octet.o \
			./obj/details_compilation.o \
			./obj/program_data.o \
			./obj/init_struct_parsing.o \
			./obj/ft_exit_clean.o \
			./obj/rev_process_reverse_binary.o \
			./obj/rev_transform_header.o \
			./obj/rev_transform_instructions.o \
			./obj/ft_is_label_chars.o \
			./obj/eval_expr.o \
			./obj/label_exist.o \
			./obj/exit_free_expression_tab.o

MAKE = make

GCC = gcc
FLAGS = -Wall -Werror -Wextra

INC = ./includes
LIB = ../libft
OBJ_PATH = ./obj

.PHONY: clean fclean all re lib

all: lib $(NAME)

$(NAME): $(OBJ)
				@$(GCC) $(FLAGS) -o $(NAME) $(OBJ) -I $(INC) -L $(LIB) -lft
				@echo "> \\033[4;masm\\033[0m  :  [\\033[38;5;214mOK\\033[0m]"

$(OBJ): ./obj/%.o : ./src/%.c
				@mkdir $(OBJ_PATH) 2> /dev/null || true
				@echo "asm >>> Add/Update $^"
	    	@$(GCC) $(FLAGS) -c -I $(INC) $< -o $@ -I $(INC)

lib:
				@$(MAKE) -C $(LIB)

clean:
				@echo Clean objects asm
				@rm -rf $(OBJ)
				@rmdir obj 2> /dev/null || true

fclean: clean
				@echo Clean asm
				@rm -rf $(NAME)

re: fclean all
