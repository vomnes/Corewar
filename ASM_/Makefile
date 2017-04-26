NAME = asm

SRC =	./src/main.c

OBJ =	./obj/main.o

MAKE = make

GCC = gcc
FLAGS = -Wall -Werror -Wextra

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
