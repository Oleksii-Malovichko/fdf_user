/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:48:51 by lseeger           #+#    #+#             */
/*   Updated: 2024/12/09 14:33:01 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft/libft.h"
# include "../libft/printf/include/ft_printf.h"
# include "MLX42/MLX42.h"
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 2048
# define HEIGHT 2048
# define TILE_SIZE 20

// colors
# define COLOR_BLACK 0x000000FFU
# define COLOR_WHITE 0xFFFFFFFFU
# define COLOR_RED 0xFF0000FFU
# define COLOR_GREEN 0x00FF00FFU
# define COLOR_BLUE 0x0000FFFFU
# define COLOR_YELLOW 0xFFFF00FFU
# define COLOR_CYAN 0x00FFFFFFU
# define COLOR_MAGENTA 0xFF00FFFFU
# define COLOR_ORANGE 0xFFA500FFU
# define COLOR_PURPLE 0x800080FFU
# define COLOR_BROWN 0xA52A2AFFU
# define COLOR_GRAY 0x808080FFU
# define COLOR_LIGHT_GRAY 0xD3D3D3FFU
# define COLOR_DARK_GRAY 0xA9A9A9FFU

# define DEFAULT_COLOR 0
# define BACKGROUND_COLOR COLOR_GRAY

// base structs
typedef struct s_point2d
{
	int			x;
	int			y;
}				t_point2d;
void			ft_set_point2d(t_point2d *point, int x, int y);
bool			ft_point_in_area(int width, int height, t_point2d *point);
void			ft_print_point2d(char *name, t_point2d *point);
void			ft_scale_point2d(t_point2d *point, float scale);
int				ft_magnitude_point2d(t_point2d *point);
void			ft_add_point2d(t_point2d *point, t_point2d *add);
void			ft_subtract_point2d(t_point2d *point, t_point2d *add);

typedef struct s_point3d
{
	int			x;
	int			y;
	int			z;
}				t_point3d;
void			ft_set_point3d(t_point3d *point, int x, int y, int z);
void			ft_print_point3d(char *name, t_point3d *point);
void			ft_add_point3d(t_point3d *point, t_point3d *add);
void			ft_subtract_point3d(t_point3d *point, t_point3d *sub);
void			ft_scale_point3d(t_point3d *point, float scale);

typedef struct s_point3d_d
{
	double		x;
	double		y;
	double		z;
}				t_point3d_d;
void			ft_set_point3d_d(t_point3d_d *point, double x, double y,
					double z);
void			ft_rotate_point(t_point3d *point, t_point3d_d *viewport);
void			ft_normalize_point2d(t_point2d *point);

typedef struct s_map
{
	int			width;
	int			height;
	int			**map;
	uint32_t	**color;
	t_point2d	pos;
}				t_map;

typedef struct s_fdf
{
	mlx_t		*mlx;
	int			width;
	int			height;
	t_map		map;
	mlx_image_t	*img;
	bool		update;
	void		(*projection_func)(t_point3d *point, t_point2d *pixel_pos);

	t_point2d	offset;
	t_point3d_d	viewpoint;
	int			tile_size;
	float		y_scale;
	float		zoom;
}				t_fdf;
void			ft_init_fdf(t_fdf *fdf, char *file_path);
void			ft_free_fdf_content(t_fdf *fdf);
void			ft_update_fdf_img(t_fdf *fdf);
void			ft_reset_fdf_view(t_fdf *fdf);

// zoom
# define START_ZOOM 0.7
# define MIN_ZOOM 0.1
# define MAX_ZOOM 3
# define ZOOM_STEP 0.07

void			ft_update_zoom_factor(t_fdf *fdf);
void			ft_zoom_in(t_fdf *fdf);
void			ft_zoom_out(t_fdf *fdf);

// y-scale
# define START_Y_SCALE 0.5
# define MIN_Y_SCALE 0.05
# define MAX_Y_SCALE 3
# define SCALE_STEP 0.01

void			ft_update_y_scale(t_fdf *fdf);
void			ft_increase_y_scale(t_fdf *fdf);
void			ft_decrease_y_scale(t_fdf *fdf);

# define MAX_RADIANT M_PI
# define MIN_RADIANT -M_PI
# define DEGREE_STEP 0.1

void			ft_update_degree(t_fdf *fdf);
void			ft_rotate_counter(t_fdf *fdf);
void			ft_rotate_clock(t_fdf *fdf);

// util functions
int				ft_get_line_count(int fd);

// map functions
int				ft_init_map(t_map *map, char *file_path);
int				ft_init_map_size(t_map *map, char *file_path);
void			ft_print_map(t_map *map, bool print_map, bool print_color);
int				ft_parse_map(t_map *map, char *file_path);
void			ft_free_map_content(t_map *map);
void			ft_draw_fdf(t_fdf *fdf);
t_point3d		ft_get_point(t_fdf *fdf, t_point2d *point);

// base functions
void			ft_error(char *msg);
char			*ft_get_file_path(int argc, char **argv);

// graphic base functions
bool			ft_put_pixel_save(mlx_image_t *img, t_point2d *point,
					uint32_t color);
void			ft_clear_img(mlx_image_t *img, unsigned int color);

void			ft_draw_line(mlx_image_t *img, t_point2d *start, t_point2d *end,
					uint32_t color);
void			ft_connect_tiles(t_fdf *fdf, t_point2d *start, t_point2d *end);

// projection functions           
void			ft_get_isometric(t_point3d *point, t_point2d *pixel_pos);
void			ft_get_parallel(t_point3d *point, t_point2d *pixel_pos);
void			ft_get_perspective(t_point3d *point, t_point2d *pixel_pos);
void			ft_get_orthographic(t_point3d *point, t_point2d *pixel_pos);
void			ft_set_isometric_projection(t_fdf *fdf);
void			ft_set_parallel_projection(t_fdf *fdf);
void			ft_set_perspective_projection(t_fdf *fdf);
void			ft_set_orthographic_projection(t_fdf *fdf);

// hooks
void			ft_hooks_setup(t_fdf *fdf);
void			ft_on_resize(int32_t width, int32_t height, void *param);
void			ft_loop(void *param);
void			ft_check_key_presses(t_fdf *fdf);
void			ft_key_hook(mlx_key_data_t key_data, void *param);

// offset functions
# define OFFSET_STEP 10

int				ft_get_screen_middle_offset_x(t_fdf *fdf);
int				ft_get_screen_middle_offset_y(t_fdf *fdf);

#endif
