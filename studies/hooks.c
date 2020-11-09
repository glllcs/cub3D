#include "learning.h"

int		key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	printf("%d pressed\n", keycode);
	if (keycode  == KEY_ESC)
		mlx_destroy_window(vars->mlx, vars->win);
}

int		mouse_hook(int button, int x, int y, t_vars *vars)
{
	(void)vars;
	printf("%d button, coordinates (%d,%d)", button, x, y);
}

int		close(int keycode, t_vars *vars)
{
	if (keycode  == KEY_ESC)
		mlx_destroy_window(vars->mlx, vars->win);
}
