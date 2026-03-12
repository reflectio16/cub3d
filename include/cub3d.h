/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:57:22 by meelma            #+#    #+#             */
/*   Updated: 2026/03/12 18:41:40 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"
# include "../gnl/get_next_line.h"

# define M_PI 3.14159265358979323846
# define WIDTH 1920
# define HEIGHT 1080
# define ELECTRIC_BLUE 0x5E00FF
# define PRUNE 0x5F0024

/*
** ============== PARSING STRUCTURES ==============
*/

typedef enum e_line_type
{
	LINE_EMPTY = 0,
	LINE_TEXTURE = 1,
	LINE_COLOR = 2,
	LINE_MAP = 3,
	LINE_INVALID = -1
}	t_line_type;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_textures;

typedef struct s_colors
{
	int		floor;
	int		ceiling;
}	t_colors;

/*
** ============== RENDERING STRUCTURES ==============
*/

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

typedef struct s_images
{
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
}	t_images;

typedef struct s_mlx
{
	void	*connection;
	void	*window;
	t_img	img;
}	t_mlx;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_dda
{
	double	pos_x;
	double	pos_y;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		screen_x;
}	t_dda;

typedef struct s_wall_floor
{
	int		i;
	int		j;
	double	x;
	double	y;
	int		pixel_x;
	int		pixel_y;
}	t_wall_floor;

typedef struct s_player_pixel
{
	double	px;
	double	py;
	int		dx;
	int		dy;
}	t_player_pixel;

typedef struct s_ray
{
	double	camera_x;
	double	x;
	double	y;
}	t_ray;

typedef struct s_contour
{
	int		base_x;
	int		base_y;
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
}	t_contour;

typedef struct s_tex
{
	int		x;
	int		y;
	double	wall_x;
	double	wall_y;
	int		width;
	int		height;
}	t_tex;

/*
** ============== MAIN DATA STRUCTURE ==============
*/

typedef struct s_data
{
	/* Map */
	char			**map;
	int				map_width;
	int				map_height;

	/* Texture paths (from parsing) */
	t_textures		textures;

	/* Colors (from parsing) */
	t_colors		colors;

	/* Loaded texture images (for rendering) */
	t_images		images;

	/* Player */
	t_player		player;

	/* Rendering helpers */
	t_dda			dda;
	t_wall_floor	wf;
	t_player_pixel	player_pixel;
	t_ray			ray;
	t_contour		contour;
	t_tex			tex;

	/* Minimap tile size */
	int				tile;
}	t_data;

typedef struct s_game
{
	t_mlx	mlx;
	t_data	data;
}	t_game;

/*
** ============== PARSING FUNCTIONS ==============
*/

/* parse_utils.c */

t_line_type	get_line_type(char *line);
int			print_error(char *msg);
int			get_line_width(t_data *data, int current_line);

/* clean.c */
void		free_split(char **arr);
void		free_data(t_data *data);
int			clean_exit(int fd, char *line, t_list **map_list);

/* parse_texture.c */
int			parse_texture(char *line, t_data *data);

/* parse_color.c */
int			parse_color(char *line, t_data *data);

/* parse_map.c */
int			add_map_line(char *line, t_list **map_list);
char		**list_to_array(t_list *list, int *height);
int			get_map_width(char **map);
int			find_player(t_data *data);

/* validate_map.c */
int			validate_map(t_data *data);

/* flood_fill.c */
int			flood_fill(char **map, int x, int y, int height);

/* is_map_closed.c */
int			check_map_closed(t_data *data);

/* init.c (parsing) */
int			parse_file(char *filename, t_data *data, t_list **map_list);
int			setup_map(t_data *data, t_list *map_list);

/*
** ============== RENDERING FUNCTIONS ==============
*/

/* game_init.c */
void		cub_init(t_game *game, t_mlx *mlx, t_data *data);
void		player_init(t_data *data);
void		plane_init(t_data *data, double k);

/* load_texture.c */
void		load_texture(t_mlx *mlx, t_img *texture, char *path);
void        load_all_textures(t_mlx *mlx, t_data *data);

/* render.c */
void        cub_render(t_mlx *mlx, t_data *data, int tile);
void		wall_floor_render(int tile, t_mlx *mlx, t_data *data);
void		player_pixel_render(int tile, t_data *data, t_mlx *mlx);
void		ray_render(int tile, t_data *data, t_mlx *mlx);

/* my_mlx_pxl.c */
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
int			my_mlx_pixel_read(t_img *data, int x, int y);
void		handle_pixel(int x, int y, t_mlx *mlx, int color);

/* events.c */
int         close_handler(t_mlx *mlx);
int			key_handler(int keysym, t_game *game);

/* move.c */
void		move_forward(t_data *data);
void		move_backward(t_data *data);
void		move_right(t_data *data);
void		move_left(t_data *data);

/* rotation.c */
void		rotate_player(t_data *data, double rot);

/* dda_debug.c */
void		dda_render(int tile, t_data *data, t_mlx *mlx);
void		dda_debug_ray(int tile, int x, t_data *data, t_mlx *mlx);

/* c_w_f_render.c */
void		draw_ceiling(int y, t_data *data, t_mlx *mlx);
void		draw_wall(int x, int y, t_data *data, t_mlx *mlx);
void		draw_floor(int y, t_data *data, t_mlx *mlx);

/* display_data.c */
void		display_data(t_mlx *mlx, t_data *data);

#endif