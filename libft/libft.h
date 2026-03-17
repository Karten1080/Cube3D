/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:18:27 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/20 19:18:47 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# ifndef FD_MAX
#  define FD_MAX 8192
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_list
{
	void			*value;
	struct s_list	*next;
}						t_list;

/*Fonction obligatoire*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *str);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int				ft_atoi(const char *nptr);
long			ft_atol(const char *nptr);
char			*ft_strdup(const char *s1);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strjoin(const char *s1, const char *s2);
char			**ft_split(const char *s, char c);
char			*ft_itoa(int n);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s1, const char *set);
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			*ft_realloc(void *ptr, size_t old_size, size_t new_size);

/*Fonction bonus*/
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/*GET_NEXT_LINE*/
char			*get_next_line(int fd);
size_t			ft_strlen_gnl(char *s);
char			*ft_strchr_gnl(char *s, int c);
char			*ft_strdup_gnl(char *s);
char			*ft_substr_gnl(char *s, unsigned int start, size_t len);
char			*ft_strjoin_gnl(char *s1, char *s2);

/*FT_PRINTF*/
int				ft_printf(const char *format, ...);
int				ft_print_char(char c);
int				ft_print_str(char *s);
int				ft_print_nbr(int n);
int				ft_print_nbru(unsigned int n);
int				ft_print_ptr(void *ptr);
int				ft_print_hex(unsigned int hex, char c);

/*Fonction additionnel*/

unsigned int	ft_atoi_base(const char *str, const char *base);
int				ft_isspace(int c);
long			ft_strtol(const char *nptr, char **endptr, int base);
void			ft_free_split(char **sp);
int				ft_strcmp(const char *s1, const char *s2);

#endif
