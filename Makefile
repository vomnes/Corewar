# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/22 16:29:16 by atrudel           #+#    #+#              #
#    Updated: 2017/05/22 18:06:15 by atrudel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: libft asm corewar

asm:
	make -C ASM_

corewar:
	make -C VM_

libft:
	make -C libft

clean:
	@make -C libft clean
	@make -C ASM_ clean
	@make -C VM_ clean

fclean:
	@make -C libft fclean
	@make -C ASM_ fclean
	@make -C VM_ fclean
	@echo ======[Clean]======

re: fclean all

.PHONY: libft clean fclean asm corewar re all
