#ifndef LEARNING_H
# define LEARNING_H
#include <mlx.h>
#include <math.h>
#include <stdio.h>

# define HOOK_KEY_DOWN		125
# define HOOK_KEY_UP		126
# define HOOK_KEY_LEFT		123
# define HOOK_KEY_RIGHT		124

# define HOOK_ENTER			36
# define HOOK_BACKSPACE		51
# define HOOK_SPACE			49
# define HOOK_ESC			53

# define HOOK_1				18
# define HOOK_2				19
# define HOOK_3				20
# define HOOK_4				21
# define HOOK_5				23
# define HOOK_6				22
# define HOOK_7				26
# define HOOK_8				28
# define HOOK_9				25
# define HOOK_0				29

# define HOOK_A				0
# define HOOK_S				1
# define HOOK_D				2
# define HOOK_W				13


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