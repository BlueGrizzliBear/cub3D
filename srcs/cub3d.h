/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbussier <cbussier@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:00:26 by cbussier          #+#    #+#             */
/*   Updated: 2020/02/28 13:56:11 by cbussier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define FUNC_PRECIS 2
# define BKG_ALPHA 0
# define BKG_RED 255
# define BKG_GREEN 255
# define BKG_BLUE 255
# define WALL_ALPHA 0
# define WALL_RED 105
# define WALL_GREEN 105
# define WALL_BLUE 105
# define CURSOR_ALPHA 64
# define CURSOR_RED 0
# define CURSOR_GREEN 255
# define CURSOR_BLUE 0
# define CURSOR_RESO_X 41
# define CURSOR_RESO_Y 41
# define CURSOR_DIFF_X 20
# define CURSOR_DIFF_Y 20
# define MM_F_ALPHA 64
# define MM_F_RED 191
# define MM_F_GREEN 191
# define MM_F_BLUE 191
# define MM_W_ALPHA 64
# define MM_W_RED 85
# define MM_W_GREEN 85
# define MM_W_BLUE 85
# define MM_S_ALPHA 64
# define MM_S_RED 255
# define MM_S_GREEN 0
# define MM_S_BLUE 0
# define MM_P_ALPHA 64
# define MM_P_RED 0
# define MM_P_GREEN 255
# define MM_P_BLUE 0
# define MM_R_ALPHA 64
# define MM_R_RED 112
# define MM_R_GREEN 128
# define MM_R_BLUE 144
# define MM_OFFSET_X 30
# define MM_OFFSET_Y 30
# define SCREEN_DISTANCE 3
# define ANG_SPEED 6
# define MVT_SPEED 1
# define FOV 60
# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LFT_AR 123
# define KEY_RGT_AR 124
# define SHIFT 257
# define CUBE_SIZE 10

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx_opengl_20191021/mlx.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct		s_pos
{
	double			x;
	double			y;
	double			ang;
}					t_pos;

typedef	struct		s_size
{
	double			x;
	double			y;
}					t_size;

typedef	struct		s_reso
{
	int				x;
	int				y;
}					t_reso;

typedef	struct		s_matrix
{
	int				d_x;
	int				d_y;
}					t_mtx;

typedef	struct		s_color
{
	unsigned int	color;
	unsigned int	alpha;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}					t_color;

typedef struct		s_func
{
	double			prec;
	double			*cos;
	double			*sin;
	double			*tan;
}					t_func;

typedef	struct		s_input
{
	char			*file_name;
	char			*charset;
	char			*line;
	int				r_r;
	int				r_no;
	int				r_so;
	int				r_we;
	int				r_ea;
	int				r_s;
	int				r_f;
	int				r_c;
	int				r_other;
	t_reso			reso;
	t_color			f_color;
	t_color			c_color;
	char			*map_lines;
	char			**map_table;
	char			**t;
	t_reso			max;
}					t_input;

typedef	struct		s_image
{
	void			*img_ptr;
	char			*img_data;
	t_color			b_color;
	t_pos			offset;
	t_reso			reso;
	int				bpp;
	int				s_l;
	int				endian;
}					t_img;

typedef struct		s_bkg
{
	t_img			*img;
}					t_bkg;

typedef struct		s_mmap
{
	t_img			*mm_img;
	t_pos			offset;
	t_pos			max;
	t_color			w_color;
	t_color			s_color;
	t_input			*input;
	t_func			*f;
}					t_mmap;

typedef struct		s_npc
{
	int				id;
	t_pos			pos;
	t_pos			center;
	t_pos			impact;
	double			diff_ang;
	double			cos_diff;
	double			sin_diff;
	double			center_dist;
	double			dist;
	t_pos			t_offset;
	double			real_size;
	double			real_pos_y;
	double			pos_y;
	double			size;
	t_color			color;
	char			*s_path;
	t_img			*s_img;
	int				speed;
	struct s_npc	*next;
}					t_npc;

typedef	struct		s_ray
{
	double			cos_ang;
	double			sin_ang;
	double			q_ang;
	double			cos_q_ang;
	double			sin_q_ang;
	double			mod_x;
	double			mod_y;
	t_pos			pos;
	double			size;
	t_pos			sqr_pos;
	t_mtx			mtx_c;
	t_mtx			mtx_one_sqr;
	t_mtx			mtx_two_sqr;
	t_mtx			mtx_three_sqr;
	t_pos			line;
	t_pos			d;
	t_reso			s;
	double			err;
	double			e2;
	t_color			color;
	t_func			*f;
	int				nb;
	t_npc			npc[64];
	double			tan_h_fov;
}					t_ray;

typedef struct		s_screen
{
	double			offset;
	t_pos			pos;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	t_img			*no_img;
	t_img			*so_img;
	t_img			*we_img;
	t_img			*ea_img;
	t_img			*current;
	double			half_len;
	double			seg_len;
	t_mtx			orientation;
	t_pos			t_offset;
	double			real_size;
	double			real_pos_y;
	double			size;
	t_color			c_color;
	t_color			w_color;
	t_color			f_color;
	t_func			*f;
}					t_screen;

typedef	struct		s_cursor
{
	t_img			*img;
	t_color			color;
	int				d_x;
	int				d_y;
	int				step;
	int				ring;
	int				mid;
	t_func			*f;
}					t_cursor;

typedef struct		s_player
{
	t_pos			pos;
	double			hp;
	double			fov;
	double			ang_speed;
	double			mvt_speed;
	t_color			color;
	t_ray			*ray;
	t_func			*f;
}					t_player;

typedef	struct		s_hotkey
{
	int				key_w;
	int				key_s;
	int				key_a;
	int				key_d;
	int				key_lft_ar;
	int				key_rgt_ar;
	int				key_lft_mouse;
	int				key_rgt_mouse;
	int				key_shift;
}					t_hotkey;

typedef	struct		s_hud
{
	double			transp;
	char			*red_path;
	t_img			*red_img;
	t_img			*red_screen;
	char			*white_path;
	t_img			*white_img;
	t_img			*white_screen;
	char			*blood_path;
	t_img			*blood_img;
	t_img			*blood_screen;
	char			*dead_path;
	t_img			*dead_img;
	t_img			*dead_screen;
}					t_hud;

typedef	struct		s_win
{
	int				save;
	int				fd;
	unsigned char	*bmp;
	t_mtx			dst;
	t_mtx			src;
	void			*mlx_ptr;
	void			*win_ptr;
	t_mmap			*mmap;
	t_bkg			*bkg;
	t_player		*player;
	t_npc			*npc;
	t_screen		*screen;
	t_cursor		*cursor;
	t_hud			*hud;
	t_hotkey		hotkey;
	t_func			*f;
	int				cb_s;
}					t_win;

t_win				*ft_new_window(void);
t_cursor			*ft_new_cursor(t_win *win);
t_screen			*ft_new_screen(t_win *win);
t_player			*ft_new_player(t_win *win);
t_bkg				*ft_new_bkg(t_win *win, t_mmap *mmap);
t_mmap				*ft_new_mmap(t_win *win);
t_color				ft_new_clr(unsigned a, unsigned r, unsigned g, unsigned b);
t_ray				*ft_new_ray(t_win *win);
t_input				*ft_new_input(t_win *win);
t_img				*ft_new_image(t_win *win);
t_npc				*ft_new_npc(t_win *win);
int					ft_parsing(char *map_file, t_win *win);
int					ft_identify(char *line, t_win *win, t_input *in);
int					ft_check_f_c(t_win *win, char id, char *line);
int					ft_check_map_integrity(t_win *win);
int					ft_join_map_lines(char *line, t_win *win, t_input *in);
int					ft_check_reso(char *line, t_win *win);
int					ft_check_path(t_win *win, char **path, int *ret, char *l);
int					ft_pass_numbers(char *str);
int					ft_pass_spaces(char *str);
char				**ft_copy_map_table(char **table);
int					ft_check_outside(char **t, t_reso pos, int size);
int					ft_check_flood_fill(t_win *win, char **table);
int					ft_check_around(char **t, t_reso pos, int size);
int					ft_error(int id, t_win *win);
int					ft_quit(t_win *win);
t_img				*ft_free_image(void *mlx_ptr, t_img *img);
char				*ft_free_string(char *str);
t_player			*ft_free_player(t_player *player);
t_npc				*ft_free_npc(t_win *win, t_npc *npc);
t_screen			*ft_free_screen(t_win *win, t_screen *screen);
t_cursor			*ft_free_cursor(t_win *win, t_cursor *cursor);
t_hud				*ft_free_hud(t_win *win, t_hud *hud);
char				**ft_free_tables(char **table);
t_input				*ft_free_input(t_input *input);
t_mmap				*ft_free_mmap(t_win *win, t_mmap *mmap);
t_bkg				*ft_free_bkg(t_win *win, t_bkg *bkg);
t_func				*ft_free_func(t_func *func);
double				ft_cos(t_func *func, double ang);
double				ft_sin(t_func *func, double ang);
double				ft_tan(t_func *func, double ang);
int					ft_init_struct(t_win *win);
int					ft_create_texture_img(t_win *win, t_img *img, char *path);
int					ft_init_textures(t_win *win, t_screen *screen, t_npc *npc);
int					ft_init_func(t_win *win, t_func *func);
int					ft_init_hotkey(t_win *win);
int					ft_init_cursor(t_win *win, t_cursor *cursor);
int					ft_init_bkg(t_win *win, t_img *img);
int					ft_init_screen(t_win *win);
int					ft_init_ray(t_win *win);
int					ft_init_pos(t_win *win, t_input *input);
int					ft_check_arg_save(char *save, t_win *win);
int					ft_create_bmp(t_win *win, unsigned char *bmp, int fd);
void				ft_screenshot(t_win *win, unsigned char *dst);
double				get_angle(t_pos new_pos, t_pos p_pos);
t_pos				ft_get_new_pos(t_win *win, t_pos p_pos, t_hotkey h);
int					ft_analyse_move(t_win *win, t_player *player, t_hotkey h);
int					ft_prep_coll_xy(t_win *win, t_player *p, t_pos new_pos);
int					ft_prep_coll_x(t_win *win, t_player *p, t_pos new_pos);
int					ft_prep_coll_y(t_win *win, t_player *p, t_pos new_pos);
int					ft_check_coll_xy(t_ray *ray, t_win *win);
int					ft_check_coll_x(t_ray *ray, t_win *win);
int					ft_check_coll_y(t_ray *ray, t_win *win);
int					ft_move_npc(t_win *win, t_player *player);
int					ft_set_mmap_image(t_win *win, t_mmap *mmap);
int					ft_raycasting(t_win *win, t_player *player, t_ray *ray);
double				ft_mod(double ang, double prec);
int					ft_pre_process_angles(t_ray *ray, double seg_ang);
int					ft_pre_process_mod(t_ray *ray, int cb_s);
int					ft_get_ray_length(t_player *player, t_ray *ray, int cb_s);
int					ft_get_ang(t_pos p_p, t_pos r_p, t_ray *r, double q_ang);
int					ft_check_impact(t_ray *ray, t_win *win);
t_mtx				ft_set_one_sqr_mtx(t_ray *ray, t_win *win);
t_pos				ft_get_sqr_pos(t_ray *ray, int cb_s, t_mtx ext);
int					ft_compare(t_pos sqr_pos, t_mmap *mmap, int cb_s);
int					ft_check_other_cases(t_ray *ray, t_win *win);
int					ft_check_npc_impact(t_win *win, t_ray *ray);
int					ft_sort_npc(t_win *win);
int					ft_draw_ray_pos(t_ray *ray, t_pos pos, t_mmap *mmap);
int					ft_init_r_beam(t_player *player, t_ray *r);
int					ft_draw_r_beam(t_ray *r, t_pos d, t_reso s, t_mmap *mmap);
int					ft_set_3d_bkg(t_win *win, t_player *player, t_ray *ray);
int					ft_set_3d_npc(t_win *win, t_player *player, t_ray *r);
int					ft_draw_3d_npc(t_win *win, t_bkg *bkg, t_screen *screen);
int					ft_draw_3d_bkg(t_win *win, t_bkg *bkg, t_screen *screen);
int					ft_chg_pxl_clr(t_img *img, int x, int y, t_color color);
int					ft_chg_pxl(t_img *d_i, t_mtx dst, t_img *s_i, t_mtx src);
int					ft_set_mmap_player(t_win *win);
int					ft_set_mmap_npc(t_win *win);
int					ft_set_hud(t_win *win, t_player *player, t_hud *hud);
int					ft_set_cursor(t_cursor *cursor, t_hotkey hotkey);

#endif
