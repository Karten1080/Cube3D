/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 05:51:35 by nistanoj          #+#    #+#             */
/*   Updated: 2026/01/31 02:09:43 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>
# include <sys/time.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define WIDTH 1920
# define HEIGHT 1080
# define TEX_SIZE 64

# define FOV 66
# define MOVE_SPEED 3.0
# define ROT_SPEED 2.0
# define MOUSE_SENS 0.005

# define KEY_W 119
# define KEY_Z 122
# define KEY_A 97
# define KEY_Q 113
# define KEY_S 115
# define KEY_D 100
# define KEY_M 109
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_DOWN 65364

# define MOUSE_LEFT 1
# define MOUSE_RIGHT 3

# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_BLUE 0x0000FF
# define COLOR_WHITE 0xFFFFFF
# define COLOR_BLACK 0x000000
# define COLOR_YELLOW 0xFFFF00

# define MM_SCALE 10
# define MM_SIZE 150
# define MM_OFFSET 20

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_vec2i
{
	int	x;
	int	y;
}	t_vec2i;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_tex
{
	t_img	img;
	int		*pixels;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		color;
}	t_tex;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
	double	move_speed;
	double	mouse_move;
	double	rot_speed;
}	t_player;

typedef struct s_map
{
	int		**grid;
	int		width;
	int		height;
	char	*no_tex;
	char	*so_tex;
	char	*we_tex;
	char	*ea_tex;
	int		floor_color;
	int		ceiling_color;
}	t_map;

typedef struct s_ray
{
	t_vec2	dir;
	t_vec2	side_dist;
	t_vec2	delta_dist;
	t_vec2i	map_pos;
	t_vec2i	step;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
}	t_ray;

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
	bool	up;
	bool	down;
	bool	mouse;
}	t_keys;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map;
	t_player	player;
	t_keys		keys;
	t_tex		textures[4];
	t_tex		*floor_tex;
	t_tex		*ceiling_tex;
	bool		game_running;
	double		frame_time;
}	t_game;

/* Parsing */
int		parse_map(char *filename, t_game *game);
int		validate_map(t_game *game);
char	*skip_whitespace(char *str);
char	*trim_newline(char *str);
int		is_map_char(char c);
int		is_config_line(char *line);
int		parse_line(char *line, t_game *game);
int		check_missing_config(t_game *game);
t_list	*read_map_file(char *filename);
int		get_map_dimensions(t_list *map_lines, t_game *game);
void	free_visited(int **visited, int height);
int		**init_visited(t_game *game);
int		count_players(t_game *game, int *px, int *py);

/* Init */
int		init_game(t_game *game);
int		init_textures(t_game *game);
int		init_player(t_game *game);

/* Raycasting */
void	raycasting(t_game *game);
void	perform_dda(t_game *game, t_ray *ray);
void	calculate_wall_distance(t_game *game, t_ray *ray);
void	calculate_wall_height(t_ray *ray);
void	determine_texture(t_ray *ray);
void	calculate_texture_x(t_game *game, t_ray *ray);

/* Rendering */
void	render_frame(t_game *game);
void	render_wall(t_game *game, int x, t_ray *ray);
void	render_floor_ceiling(t_game *game);
void	render_minimap(t_game *game);

/* Player movement */
void	move_player(t_game *game);
void	rotate_player(t_game *game, double angle);
int		check_collision(t_game *game, double x, double y);

/* Events */
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		handle_mouse(t_game *game);
int		close_game(t_game *game);

/* Utils */
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		get_texture_pixel(t_tex *tex, int x, int y);
void	free_game(t_game *game);
void	error_exit(char *msg, t_game *game);
int		player_can_move(t_game *game, int px, int py);

#endif
