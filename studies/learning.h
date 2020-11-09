#ifndef LEARNING_H
# define LEARNING_H
#include <mlx.h>
#include <math.h>
#include <stdio.h>

# define KEY_ARROW_DOWN		125
# define KEY_ARROW_UP		126
# define KEY_ARROW_LEFT		123
# define KEY_ARROW_RIGHT	124

# define KEY_ENTER			36
# define KEY_BACKSPACE		51
# define KEY_SPACE			49
# define KEY_ESC			53

# define KEY_1				18
# define KEY_2				19
# define KEY_3				20
# define KEY_4				21
# define KEY_5				23
# define KEY_6				22
# define KEY_7				26
# define KEY_8				28
# define KEY_9				25
# define KEY_0				29

# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_W				13


typedef struct  s_data {
	void    *img;
	char    *addr;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}               t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;


int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		get_rgb(int trgb);
int		add_shade(double distance, int color);
int		get_opposite (int color);
void  	make_square(t_data *img, double x_origin, double y_origin, int size);
void  	make_circle(t_data *img, int x_center, int y_center, int radius);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
int		close(int keycode, t_vars *vars);

#endif