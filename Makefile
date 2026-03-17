# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asmati <asmati@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/22 05:51:53 by nistanoj          #+#    #+#              #
#    Updated: 2026/01/30 14:39:39 by asmati           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
MATHFLAGS	= -lm
MLXFLAGS	= -L./mlx -lmlx -lXext -lX11
DEPFLAGS	= -MMD -MP

LIBFT		= libft/libft.a
LIBFTDIR	= libft
MLXDIR		= mlx

SRCDIR		= srcs
OBJDIR		= objs
INCDIR		= include

COMMON		= srcs/parsing/parse_map.c \
			  srcs/parsing/parse_utils.c \
			  srcs/parsing/parse_file.c \
			  srcs/parsing/check_map.c \
			  srcs/parsing/validate_map.c \
			  srcs/events/events_utils.c \
			  srcs/player/player_utils.c \
			  srcs/init/init_game.c \
			  srcs/init/init_textures.c \
			  srcs/init/init_player.c \
			  srcs/raycasting/raycasting.c \
			  srcs/raycasting/raycasting_utils.c \
			  srcs/rendering/render_floor_ceiling.c \
			  srcs/rendering/render_walls.c \
			  srcs/utils/utils.c \
			  srcs/utils/free.c

MANDATORY 	= srcs/main.c \
			  srcs/rendering/render_frame.c \
			  srcs/events/key_events.c \
			  srcs/player/movement.c

BONUS_FILES = srcs/main_bonus.c \
			  srcs/events/events_bonus.c \
			  srcs/rendering/render_frame_bonus.c \
			  srcs/player/movement.c \
			  srcs/rendering/render_minimap_bonus.c

OBJS_COMM	= $(COMMON:srcs/%.c=objs/%.o)
OBJS_MANDAT	= $(MANDATORY:srcs/%.c=objs/%.o)
OBJS_BONUS	= $(BONUS_FILES:srcs/%.c=objs/%.o)
DEPS		+= $(BONUS_FILES:.o=.d)
DEPS		+= $(MANDATORY:.o=.d)
DEPS		+= $(COMMON:.o=.d)

GREEN		= \033[0;32m
RED			= \033[0;31m
YELLOW		= \033[0;33m
CYAN		= \033[0;36m
BOLD		= \033[1m
NC			= \033[0m

all: $(NAME)

$(NAME): $(LIBFT) mlx $(OBJS_COMM) $(OBJS_MANDAT)
	@if [ -f .bonus ]; then \
		echo "$(YELLOW)Bonus detected. Rebuilding for mandatory...$(NC)"; \
		rm -f .bonus; \
		make -s re; \
	else \
		echo "$(YELLOW)Linking $(NAME)...$(NC)"; \
		$(CC) $(CFLAGS) $(OBJS_COMM) $(OBJS_MANDAT) $(LIBFT) $(MLXFLAGS) $(MATHFLAGS) -o $(NAME); \
		echo "$(GREEN)✓ $(NAME) compiled successfully!$(NC)"; \
	fi

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(DEPFLAGS) -I$(INCDIR) -I$(LIBFTDIR) \
	-I$(MLXDIR) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(NC)"
	@make -C $(LIBFTDIR) --silent
	@echo "$(GREEN)✓ Libft compiled!$(NC)"

mlx:
	@if [ ! -d "$(MLXDIR)" ]; then \
		echo "$(YELLOW)Cloning MiniLibX...$(NC)"; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLXDIR); \
	fi
	@echo "$(YELLOW)Compiling MiniLibX...$(NC)"
	@make -s -C $(MLXDIR) --silent 2>/dev/null || true
	@echo "$(GREEN)✓ MiniLibX compiled!$(NC)"

bonus: $(LIBFT) mlx $(OBJS_COMM) $(OBJS_BONUS)
	@echo "$(YELLOW)Linking Bonus $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS_COMM) $(OBJS_BONUS) $(LIBFT) $(MLXFLAGS) \
	$(MATHFLAGS) -o $(NAME)
	@touch .bonus

norminette:
	@echo "$(CYAN)[ ℹ ] Running norminette $(BOLD)BY NISTANOJ...$(NC)"
	@if command -v norminette > /dev/null 2>&1; then \
		NORM_CMD="norminette"; \
	elif command -v python3 -m norminette > /dev/null 2>&1; then \
		NORM_CMD="python3 -m norminette"; \
	else \
		echo "$(RED)[ ✗ ] Norminette is not installed.$(NC)"; \
		echo "$(CYAN)[ ℹ ] Norminette check uncompleted.$(NC)"; \
		exit 1; \
	fi; \
	TARGET="$(filter-out $@,$(MAKECMDGOALS))"; \
	if [ -z "$$TARGET" ]; then \
		TARGET="."; \
	else \
		echo "$(YELLOW)[ ℹ ] Checking target(s): $(BOLD)$$TARGET$(NC)"; \
	fi; \
	OUTPUT=$$($$NORM_CMD $$TARGET 2>&1) ; \
	OUTPUT=$$(echo "$$OUTPUT" | sed '/Setting locale/d'); \
	FILTERED=$$(echo "$$OUTPUT" | grep -v ": OK!"); \
	if [ -n "$${FILTERED}" ]; then \
		echo "$$OUTPUT" | grep -v ": OK!"; \
		echo "$(RED)[ ✗ ] Norminette found errors !$(NC)"; \
	else \
		echo "$(GREEN)[ ✓ ] Norminette $(BOLD)passed !$(NC)"; \
	fi;
	@exit 0

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean --silent
	@echo "$(GREEN)✓ Clean done!$(NC)"

fclean: clean
	@echo "$(RED)Removing executable...$(NC)"
	@rm -f $(NAME)
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean --silent
	@make -C $(MLXDIR) clean --silent 2>/dev/null || true
	@if [ -f .bonus ]; then \
		rm -f .bonus; \
	fi
	@echo "$(GREEN)✓ Full clean done!$(NC)"

re: fclean all

rebonus: fclean bonus

test: re
	@./cub3D maps/map1.cub

testbonus: rebonus
	@./cub3D maps/dungeon.cub

.PHONY: all mlx bonus norminette clean fclean re rebonus test testbonus
