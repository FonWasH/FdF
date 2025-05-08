/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:59:14 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 06:46:54 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* ************************************************************************** */
/*                                                                            */
/*                                  INCLUDE                                   */
/*                                                                            */
/* ************************************************************************** */

/* LIBFT */
# include "libft.h"

/* MINILIBX */
# include "mlx.h"
# include "mlx_int.h"

/* MATH */
# include <math.h>
# include <errno.h>

/* ************************************************************************** */
/*                                                                            */
/*                                   DEFINE                                   */
/*                                                                            */
/* ************************************************************************** */

/* ERROR */
# define ERROR			"Error: "
# define ERR_ARG		"Invalid arguments"
# define ERR_MEM		"Memory allocation failed"
# define ERR_MLX		"MLX initialization failed"
# define ERR_WIN		"New window creation failed"
# define ERR_IMG		"New image creation failed"
# define ERR_GET		"Get image address failed"

/* WINDOW */
# define WIN_WIDTH		1920
# define WIN_HEIGHT		1080
# define WIN_TITLE		"FIL DE FER"

/* MAP */
# define MAP_SCALE		10
# define MAP_ANGLE_MAX	360
# define MAP_ZOOM_MAX	100
# define MAP_ZOOM_MIN	0.1
# define MAP_DEPTH_MAX	50
# define MAP_DEPTH_MIN	-50

/* INFO */
# define I_POS_X		5
# define I_POS_Y		5
# define I_OFFSET_X		6
# define I_OFFSET_Y		15
# define I_BOX_SIZE		10
# define I_BOX_POS		155
# define I_LINE_COUNT	33
# define I_SEP			"-------------------------------"
# define I_NAME			"Name         :"
# define I_SIZE			"Size         :"
# define I_POS 			"Position     :"
# define I_AXIS_X	 	"Axis X       :"
# define I_AXIS_Y	 	"Axis Y       :"
# define I_AXIS_Z	 	"Axis Z       :"
# define I_ZOOM			"Zoom         :"
# define I_DEPTH		"Depth        :"
# define I_PRO	 		"Projection   :"
# define I_COLOR 		"Color"
# define I_COLOR_L		"  Lowest     :"
# define I_COLOR_M		"  Middle     :"
# define I_COLOR_H		"  Highest    :"
# define I_KEY			"Key bindings"
# define I_MOUSE		"Mouse control"
# define I_L_HIDE		"  Hide Info  :"
# define I_L_FAST		"  Fast Mode  :"
# define I_L_MOVE		"  Move       :"
# define I_L_AXIS_X		"  Axis X     :"
# define I_L_AXIS_Y		"  Axis Y     :"
# define I_L_AXIS_Z		"  Axis Z     :"
# define I_L_ZOOM		"  Zoom       :"
# define I_L_DEPTH		"  Depth      :"
# define I_L_PRO		"  Projection :"
# define I_L_COLOR		"  Color      :"
# define I_L_RESET		"  Reset      :"
# define I_L_CLOSE		"  Close      :"
# define I_K_HIDE		"Tab"
# define I_K_FAST		"Shift"
# define I_K_MOVE		"W A S D"
# define I_K_AXIS_X		"Arrow Up/Down"
# define I_K_AXIS_Y		"Arrow Left/Right"
# define I_K_AXIS_Z		"Q E"
# define I_K_ZOOM		"R F"
# define I_K_DEPTH		"T G"
# define I_K_PRO		"V"
# define I_K_COLOR		"Z X C"
# define I_K_RESET		"Space"
# define I_K_CLOSE		"Escape"
# define I_M_MOVE		"Left Click"
# define I_M_AXIS		"Right Click"
# define I_M_ZOOM		"Mouse Wheel"
# define I_M_PRO		"Middle Click"
# define I_PRO_ISO		"Isometric"
# define I_PRO_PAR 		"Parallel"
# define I_SIZE_SEP		" x "
# define I_DOUBLE_DOT	"."
# define I_COLOR_B		0x0080FF

/* CONTROL PRECISION */
# define M_MOVE_P		1000
# define M_MOVE_F		900
# define M_AXIS_P		1000000
# define M_AXIS_F		900000
# define M_ZOOM_P		0.1
# define M_ZOOM_F		0.9
# define K_MOVE_P		0.50
# define K_MOVE_F		5.50
# define K_AXIS_P		0.001
# define K_AXIS_F		0.009
# define K_ZOOM_P		0.005
# define K_ZOOM_F		0.045
# define K_DEPT_P		0.01
# define K_DEPT_F		0.09

/* COLOR */
# define C_RED			0xFF0000
# define C_GREEN		0x00FF00
# define C_BLUE			0x0000FF
# define C_YELLOW		0xFFFF00
# define C_CYAN			0x00FFFF
# define C_MAGENTA		0xFF00FF
# define C_ORANGE		0xFF8000
# define C_TURQUOISE	0x00FF80
# define C_PURPLE		0x8000FF	
# define C_WHITE		0xFFFFFF
# define C_GRAY			0x808080
# define C_BLACK		0x000000

/* MISC */
# define REQUIRED_ARGS	2
# define BYTE			8
# define SPACE			' '
# define SLASH			'/'
# ifndef DEBUG
#  define DEBUG			0
# endif

/* ************************************************************************** */
/*                                                                            */
/*                                    ENUM                                    */
/*                                                                            */
/* ************************************************************************** */

/* PROJECTION */
typedef enum e_pro
{
	ISOMETRIC,
	PARALLEL
}	t_pro;

/* MOUSE */
typedef enum e_emouse
{
	NO_CLICK,
	LEFT_CLICK,
	MIDDLE_CLICK,
	RIGHT_CLICK,
	WHEEL_UP,
	WHEEL_DOWN
}	t_emouse;

/* COLOR */
typedef enum e_color
{
	RED,
	GREEN,
	BLUE,
	YELLOW,
	CYAN,
	MAGENTA,
	ORANGE,
	TURQUOISE,
	PURPLE,
	WHITE,
	GRAY,
	BLACK,
}	t_color;

/* ************************************************************************** */
/*                                                                            */
/*                                 STRUCTURE                                  */
/*                                                                            */
/* ************************************************************************** */

/* KEY */
typedef struct s_key
{
	bool	fast_mode;
	bool	move_up;
	bool	move_down;
	bool	move_left;
	bool	move_right;
	bool	axis_x_up;
	bool	axis_x_down;
	bool	axis_y_up;
	bool	axis_y_down;
	bool	axis_z_up;
	bool	axis_z_down;
	bool	zoom_in;
	bool	zoom_out;
	bool	depth_up;
	bool	depth_down;
}			t_key;

/* MOUSE */
typedef struct s_mouse
{
	int		x;
	int		y;
	bool	left;
	bool	right;
}			t_mouse;

/* IMAGE */
typedef struct s_imgb
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		len;
	int		end;
}			t_imgb;

/* COLOR SQUARE */
typedef struct s_cb
{
	int		x;
	int		xm;
	int		ly;
	int		lym;
	int		my;
	int		mym;
	int		hy;
	int		hym;
}			t_cb;

/* INFO */
typedef struct s_info
{
	bool	visible;
	t_imgb	img;
	int		width;
	int		height;
	int		pos_x;
	t_cb	color_box;
}			t_info;

typedef struct s_line
{
	int		delta_x;
	int		delta_y;
	int		step_x;
	int		step_y;
	int		error;
	int		error_double;
	int		len;
	int		i;
	double	ratio;
}			t_line;

typedef struct s_point
{
	int		x;
	int		y;
	int		draw_x;
	int		draw_y;
	int		next_draw_x;
	int		next_draw_y;
	int		color;
	int		color_next;
}			t_point;

/* DATA BACKUP */
typedef struct s_datab
{
	double	pos_x;
	double	pos_y;
	double	axis_x;
	double	axis_y;
	double	axis_z;
	double	zoom;
	double	depth;
	t_pro	pro;
	t_color	color_l;
	t_color	color_m;
	t_color	color_h;
}			t_datab;

/* MAP */
typedef struct s_map
{
	bool	refresh;
	char	*name;
	t_imgb	img;
	int		**val;
	int		z_min;
	int		z_max;
	int		width;
	int		height;
	double	pos_x;
	double	pos_y;
	double	axis_x;
	double	axis_y;
	double	axis_z;
	double	zoom;
	double	depth;
	t_pro	pro;
	t_point	p;
	t_color	color_l;
	t_color	color_m;
	t_color	color_h;
	t_datab	backup;
}			t_map;

/* DATA */
typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_info	info;
	t_key	key;
	t_mouse	mouse;
}			t_data;

/* ************************************************************************** */
/*                                                                            */
/*                                 PROTOTYPE                                  */
/*                                                                            */
/* ************************************************************************** */

/* ERROR */
void	ft_error(char *error, t_data *data, char *str, char **tab);

/* UTILS */
void	ft_init(t_data *data, char *map_path);
void	ft_hook(t_data *data);
void	ft_destroy(t_data *data);
int		ft_close(t_data *data);

/* WINDOW HELPER */
void	ft_init_window(t_data *data);	
int		ft_handle_win_config(int width, int height, t_data *data);

/* IMAGE HELPER */
void	ft_new_image(t_data *data, t_imgb *img, int width, int height);
void	ft_put_pixel(t_imgb *img, int x, int y, int color);

/* KEY HELPER */
void	ft_init_keys(t_data *data);
void	ft_refresh_keys(t_data *data);
int		ft_key_press(int key, t_data *data);
int		ft_key_release(int key, t_data *data);

/* KEY UITLS */
void	ft_refresh_axis_key(t_data *data);
void	ft_axis_key_press(int key, t_data *data);
void	ft_axis_key_release(int key, t_data *data);

/* MOUSE HELPER */
void	ft_init_mouse(t_data *data);
int		ft_button_press(int button, int x, int y, t_data *data);
int		ft_button_release(int button, int x, int y, t_data *data);
int		ft_mouse_motion(int x, int y, t_data *data);

/* COLOR HELPER */
//int		ft_gradient_color(double ratio, int color_l, int color_h);
int		ft_height_color(t_data *data, int z);
int		ft_line_color(t_data *data, t_point p, double ratio);
int		ft_info_color(t_data *data, int x, int y, t_cb box);

/* COLOR UTILS */
int		ft_get_color(t_color color);
int		ft_create_color(int r, int g, int b);
int		ft_get_red(int color);
int		ft_get_green(int color);
int		ft_get_blue(int color);

/* DRAW HELPER */
void	ft_draw_map(t_data *data, t_point *p);

/* DRAW UITLS */
void	rotate_x(double *y, double *z, double angle);
void	rotate_y(double *x, double *z, double angle);
void	rotate_z(double *x, double *y, double angle);

/* CHECK UTILS */
void	ft_check_map_values(t_data *data);
void	ft_check_map_refresh(t_data *data);

/* MAP HELPER */
void	ft_init_map(t_data *data, char *map_path);
void	ft_refresh_map(t_data *data);

/* MAP UTILS */
void	ft_parse_map(t_data *data, char *map_path);
void	ft_reset_map(t_data *data);

/* INFO HELPER */
void	ft_init_info(t_data *data);
void	ft_refresh_info(t_data *data);

/* INFO UTILS */
void	ft_info_put_str(t_data *data, int offset, char *str, char *label);
void	ft_info_put_nbr(t_data *data, int offset, int n, char *label);
void	ft_info_put_fnbr(t_data *data, int offset, double n, char *label);
int		ft_line_pos(bool first);

/* STRING UTILS */
char	*ft_size_str(t_data *data, int width, int height);
char	*ft_double_str(t_data *data, double n);
char	*ft_pro_str(t_pro projection);

#endif
