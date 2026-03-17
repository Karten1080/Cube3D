# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 16:35:06 by nistanoj          #+#    #+#              #
#    Updated: 2026/01/20 19:18:43 by nistanoj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -ggdb
COMPILE		=	$(CC) $(CFLAGS)
DEPFLAGS	=	-MMD -MP
RM			=	rm -rf

DIR_SRCS	=	srcs/
SRC_FILES	=	is_funcs/ft_isalnum.c \
				is_funcs/ft_isalpha.c \
				is_funcs/ft_isascii.c \
				is_funcs/ft_isdigit.c \
				is_funcs/ft_isprint.c \
				is_funcs/ft_isspace.c \
				conv_funcs/ft_atoi.c \
				conv_funcs/ft_atol.c \
				conv_funcs/ft_atoi_base.c \
				conv_funcs/ft_itoa.c \
				conv_funcs/ft_tolower.c \
				conv_funcs/ft_toupper.c \
				conv_funcs/ft_strtol.c \
				str_funcs/ft_strchr.c \
				str_funcs/ft_strdup.c \
				str_funcs/ft_strlcat.c \
				str_funcs/ft_strlcpy.c \
				str_funcs/ft_strlen.c \
				str_funcs/ft_strcmp.c \
				str_funcs/ft_strncmp.c \
				str_funcs/ft_strnstr.c \
				str_funcs/ft_strrchr.c \
				str_funcs/ft_strjoin.c \
				str_funcs/ft_split.c \
				str_funcs/ft_substr.c \
				str_funcs/ft_strtrim.c \
				str_funcs/ft_strmapi.c \
				str_funcs/ft_striteri.c \
				mem_funcs/ft_memset.c \
				mem_funcs/ft_bzero.c \
				mem_funcs/ft_calloc.c \
				mem_funcs/ft_memcpy.c \
				mem_funcs/ft_memmove.c \
				mem_funcs/ft_memchr.c \
				mem_funcs/ft_memcmp.c \
				mem_funcs/ft_realloc.c \
				put_funcs/ft_putchar_fd.c \
				put_funcs/ft_putstr_fd.c \
				put_funcs/ft_putendl_fd.c \
				put_funcs/ft_putnbr_fd.c \
				lst_funcs/ft_lstnew.c \
				lst_funcs/ft_lstadd_front.c \
				lst_funcs/ft_lstsize.c \
				lst_funcs/ft_lstlast.c \
				lst_funcs/ft_lstadd_back.c \
				lst_funcs/ft_lstdelone.c \
				lst_funcs/ft_lstclear.c \
				lst_funcs/ft_lstiter.c \
				lst_funcs/ft_lstmap.c \
				printf_funcs/ft_print_char.c \
				printf_funcs/ft_print_str.c \
				printf_funcs/ft_print_nbr.c \
				printf_funcs/ft_print_hex.c \
				printf_funcs/ft_print_ptr.c \
				printf_funcs/ft_printf.c \
				gnl_funcs/get_next_line.c \
				gnl_funcs/get_next_line_utils.c \
				utils_funcs/ft_free_split.c

SRCS		=	$(addprefix $(DIR_SRCS), $(SRC_FILES))
DIR_OBJ		=	obj/
OBJ			=	$(SRCS:%.c=$(DIR_OBJ)%.o)
DEPS		=	$(OBJ:.o=.d)

TOTAL_FILES := $(words $(SRCS))

# couleur additionnelle

# ---- Colors ----
RED				=	\033[31m
GREEN			=	\033[32m
YELLOW			=	\033[33m
BLUE			= 	\033[34m
CYAN			=	\033[36m
BOLD			=	\033[1m
RESET			=	\033[0m

all:			$(NAME)

$(NAME):		$(OBJ)
	@ar rcs $@ $^

$(DIR_OBJ)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@ -fPIE

-include 		$(DEPS)

clean:
	@echo "$(RED)[🧹 ] Removing obj from $(BOLD)$(NAME)...$(RESET)"
	@$(RM) $(DIR_OBJ)

fclean:			clean
	@echo "$(RED)[🧹 ] Removing $(BOLD)$(NAME)...$(RESET)"
	@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
