/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:09:57 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/31 14:59:16 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <wchar.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define L_GREEN	"\x1b[92m"
# define Y_GREEN	"\x1b[38;5;190m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define WHITE_BLUE		"\x1b[38;5;27m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define GOLD		"\x1b[38;5;214m"
# define BOLD		"\x1b[1;m"
# define ITALIC		"\x1b[3;m"
# define UNDERLINE	"\x1b[4;m"
# define RESET		"\x1b[0m"
# define CLEAN		"\033[H\033[2J"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
int					ft_index(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *big, const char *little,
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isspace(int c);
int					ft_islower(int c);
int					ft_isxdigit(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);

char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_end(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstsize(t_list *list);
void				ft_lst_display_s(t_list *list);
void				ft_lst_display_int(t_list *list);
t_list				*ft_lst_strsplit(char const *s, char c);

void				ft_swap(int *a, int *b);
int					ft_isupper(int c);
int					ft_min(int x, int y, int z);
int					ft_hex_to_dec(char *hex);
int					ft_pow(int nb, int power);

char				*ft_strnjoin(char const *s1, char const *s2, size_t n);
size_t				ft_index_occ(const char *s, int c);
char				*ft_strndup(const char *s1, size_t n);
void				ft_strddel(char *str);
char				*ft_itoa_base(long long int nb, int base);
char				*ft_strcjoin(char const *src, char c);
char				*ft_lltoa(long long int nb);
long long int		ft_lltoi(const char *nptr);

wint_t				ft_putwchar(wchar_t wc);
void				ft_putwstr(const wchar_t *wc);
void				ft_putnwstr(const wchar_t *wc, size_t n);
size_t				ft_wstrlen(const wchar_t *wc);

int					get_next_line(const int fd, char **line);

#endif
