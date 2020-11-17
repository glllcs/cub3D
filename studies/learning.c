#include "learning.h"

#define WIN1_SX		600
#define WIN1_SY		600
#define IM1_SX		500
#define IM1_SY		500


void  my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char  *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	t_vars	vars;
	t_data  img;
	t_data	img2;
	char	*data1;
	int	bpp1;
	int	sl1;
	int	endian1;
	
	if (!(vars.mlx = mlx_init()))
	{
		printf("KO!\n");
		exit(1);
	}

	if (!(vars.win = mlx_new_window(vars.mlx, WIN1_SX, WIN1_SY, "Nova Janela")))
	{
		printf("KO!!\n");
		exit(1);
	}

	if (!(img.img = mlx_new_image(vars.mlx, IM1_SX, IM1_SY)))
	{
		printf("KO!!!"\n);
		exit(1);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	make_square(&img,200,100,300);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	sleep(2);

	mlx_destroy_image(vars.mlx, img.img);
	if (!(img.img = mlx_new_image(vars.mlx, IM1_SX, IM1_SY)))
	{
		printf("KO!!!!"\n);
		exit(1);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	make_circle(&img,200,100,100);
	sleep(2);

	mlx_clear_window(vars.mlx,vars.win);
	color_map_1(&vars, WIN1_SX, WIN1_SY);
	sleep(2);

	if(!(img2.img = mlx_new_image(vars.mlx, IM1_SX, IM1_SY)))
	{
		printf("KO!!!!!"\n);
		exit(1);
	}
	data1 = mlx_get_data_addr(img2.img, &bpp1, &sl1, &endian1);


	mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_mouse_hook(vars.win, mouse_hook, &vars);
	//mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	//mlx_hook(vars.win, 25, 0L, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
