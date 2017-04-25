NAME = libft.a
SRC = ft_lstadd.c ft_memdel.c	ft_strcat.c	ft_strlcat.c ft_strrchr.c \
			ft_lstdel.c ft_memmove.c ft_strchr.c ft_strsplit.c \
			ft_lstdelone.c ft_memset.c ft_strclr.c ft_strlen.c ft_strstr.c \
			ft_atoi.c	ft_lstiter.c ft_putchar.c ft_strcmp.c	ft_strmap.c \
			ft_strsub.c ft_bzero.c ft_lstmap.c ft_putchar_fd.c ft_strcpy.c \
			ft_strmapi.c ft_strtrim.c ft_isalnum.c ft_lstnew.c ft_putendl.c \
			ft_strdel.c ft_strncat.c ft_tolower.c ft_isalpha.c ft_memalloc.c \
			ft_putendl_fd.c ft_strdup.c	ft_strncmp.c ft_toupper.c ft_isascii.c \
			ft_memccpy.c ft_putnbr.c ft_strequ.c ft_strncpy.c ft_isdigit.c \
			ft_memchr.c ft_putnbr_fd.c ft_striter.c	ft_strnequ.c ft_isprint.c \
			ft_memcmp.c	ft_putstr.c	ft_striteri.c	ft_strnew.c ft_itoa.c \
			ft_memcpy.c	ft_putstr_fd.c ft_strjoin.c ft_strnstr.c ft_islower.c \
			ft_isspace.c ft_isupper.c ft_min.c ft_swap.c ft_find_c.c \
			ft_lst_display_s.c ft_lst_display_int.c ft_lstsize.c ft_lstadd_end.c \
			ft_lst_strsplit.c ft_strnjoin.c ft_strndup.c ft_strddel.c ft_itoa_base.c \
			ft_strcjoin.c ft_putwchar.c ft_putwstr.c ft_wstrlen.c ft_lltoa.c \
			ft_lltoi.c ft_putnwstr.c ft_isxdigit.c ft_pow.c ft_hex_to_dec.c \
			get_next_line.c ft_index.c
SRC_PF =	./ft_printf/check_errors.c ./ft_printf/convert_binary.c \
			./ft_printf/convert_char.c ./ft_printf/convert_date.c \
			./ft_printf/convert_hex.c ./ft_printf/convert_octal.c \
			./ft_printf/convert_ptr.c ./ft_printf/convert_signed.c \
			./ft_printf/convert_string.c ./ft_printf/convert_unsigned.c \
			./ft_printf/convert_wstr.c ./ft_printf/ft_is.c \
			./ft_printf/ft_printf.c ./ft_printf/get_value.c \
			./ft_printf/manage_date.c ./ft_printf/manage_hex.c \
			./ft_printf/manage_octal.c ./ft_printf/manage_octal_2.c \
			./ft_printf/manage_signed.c ./ft_printf/manage_wstr.c \
			./ft_printf/parsing_one.c ./ft_printf/parsing_two.c \
			./ft_printf/useful.c ./ft_printf/wchar.c

OBJET = $(SRC:.c=.o)
OBJET_PF = $(SRC_PF:.c=.o)
FLAGS = -Wall -Wextra -Werror

.PHONY: clean fclean all re

all: $(NAME)

$(NAME):	libft $(OBJET) libft_ok pf $(OBJET_PF) pf_ok
			@ar rc $(NAME) $(OBJET) $(OBJET_PF)
			@ranlib $(NAME)
			@echo "> Library :  [\\033[32mOK\\033[0m]"

libft :
		@echo -n \ \ \ \ libft\ :\ \

libft_ok :
		@echo " [\\033[32mOK\\033[0m]"
pf:
		@echo -n ft_printf :\ \

pf_ok :
		@echo " [\\033[32mOK\\033[0m]"

$(OBJET) : ./%.o : ./%.c
		@echo -n \#
		@gcc -c $(FLAGS) $^ -o $@ -I includes

$(OBJET_PF) : ./ft_printf/%.o : ./ft_printf/%.c
		@echo -n \#
		@gcc -c $(FLAGS) $^ -o $@ -I includes

clean:
		@echo Clean objects $(NAME)
		@rm -rf $(OBJET) $(OBJET_PF)

fclean: clean
		@echo Clean $(NAME)
		@rm -rf $(NAME)

re: fclean all
