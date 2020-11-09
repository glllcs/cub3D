#include "learning.h"

void  my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char  *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	t_vars	vars;
	//t_data  img;
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 600, "Nova Janela");
	//img.img = mlx_new_image(vars.mlx, 1000, 600);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//make_square(&img,200,100,300);
	//make_circle(&img,200,100,100);
	//mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	//mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_mouse_hook(vars.win, mouse_hook, &vars);
	//mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_hook(vars.win, 25, 0L, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}