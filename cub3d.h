/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:22:44 by bkhatib           #+#    #+#             */
/*   Updated: 2023/02/28 11:52:03 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <sys/errno.h>
# include <float.h>
# include "mlx.h"

/* Windows */
// #define KEY_UP 122
// #define KEY_DOWN 115
// #define KEY_RIGHT 100
// #define KEY_LEFT 113
// #define KEY_ESC 65307
/* Mac */
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_RIGHT 2
# define KEY_LEFT 0
# define KEY_ESC 53

# define SCREEN_H 720
# define SCREEN_W 1080

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_map
{
	char		**map;
	int			row;
	int			col;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*filename;
	char		starting_pos;
	t_color		floor_color;
	t_color		ceilling_color;
	t_vector	player;
}	t_map;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		len;
	int		bpp;
	int		endian;
	int		*arr;
	int		width;
	int		height;
}	t_img;

typedef struct s_program
{
	void		*mlx;
	void		*win_ptr;
	char		**cub_content;
	t_map		map;
	t_img		img;
	t_img		tex_north_img;
	t_img		tex_south_img;
	t_img		tex_west_img;
	t_img		tex_east_img;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
	double		wallx;
	double		tex_pos;
	double		tex_step;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			map_x;
	int			map_y;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			x;
	int			tex_x;
	int			tex_y;
	int			screen_w;
	int			screen_h;
}				t_program;

/* Init functions */
void	init_mlx_win_pos(t_program *p);
void	init_color(t_color *color);
void	init_map(t_map *map);
void	init_game(t_program *game);

/* movements functions */
int		move(int key, t_program *p);

/* raycast functions */
void	update_camera_raydir_delatdist(t_program *p);
void	get_step_and_side_dist(t_program *p);
void	search_wall(t_program *p);
void	calculate_wall_size(t_program *p);

/* rendering functions */
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_vertical_line(t_program *p, int ceilling_color, int floor_color);
int		rgb_to_int(t_color color);
t_img	get_tex(t_program *game_ptr);
void	init_tex(t_program *game_ptr, t_img tex);
void	put_tex(t_program *game_ptr, t_img tex);

/* Parser functions */
void	parser(t_program *ptr);
int		check_extension(char *src, char *to_find);
void	get_cub(t_program *ptr);
void	check_cub(char **content);
void	check_cub_texture(char **content, int *i);
void	check_cub_colors(char **content, int *i);
void	get_map_textures(t_program *game_ptr);
void	get_rgb(t_color *color, char **str);
void	get_colors(t_program *ptr);
void	get_map(t_program *ptr);
void	get_player_pos(t_map *map);
void	check_map(char **map);
int		check_player_surroundings(char **map, int row, int col);
void	check_full_map(t_map map);
void	map_checks2(t_map map, int row, int col);
int		check_extended_wall(char **map, int row);
int		check_wall(char **map, int row, int col);
int		check_wall2(char **map, int row, int i);

/* Utils functions*/
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_error(char *error);
char	**ft_split(char *str, char *sap);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(char *s1);
int		ft_strlen(char *str);
int		nbr_lines(char *filename);
char	*ft_strndup(char *s1, int n);
char	*get_next_line(int fd);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strcmp(char *s1, char *s2);
int		is_saperator(char c, char *sap);
int		count_words(char *str, char *sap);
char	*ft_strdup_w(char *str, int *index, char *sap);
void	free_split(char **tab);
int		check_new_line(char *str);
int		in_charset(char c, char *set);
int		get_map_len(t_program *ptr);
void	ft_close(t_program *game);

#endif