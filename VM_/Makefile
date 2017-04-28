# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 15:21:01 by atrudel           #+#    #+#              #
#    Updated: 2017/04/28 17:39:43 by atrudel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

LIB_PATH = ../libft
OBJ_PATH = ./obj
SRC_PATH = ./src
INC_PATH = ./includes

SRC_FILES =	corewar.c

INC_FILES = vm.h

SRC = $(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_FILES:.c=.o)) \
# Ajouter op.o

INC = $(addprefix $(INC_PATH)/, $(INC_FILES))

FLAGS = -Wall -Wextra -Werror

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
