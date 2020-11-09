#include "learning.h"

void  make_square(t_data *img, double x_origin, double y_origin, int size)
{
	double		x;
	double		y;
	int			color;

	y = y_origin;
	color = create_trgb(0,255,137,2);
	while (y <= y_origin + size)
	{
		x = x_origin;
		while (x <= x_origin + size)
		{
			if ((int)x % (size / 10) == 0)
			{
				color = get_opposite(color);
				color = add_shade(y*0.001,color);
			}
			my_mlx_pixel_put (img, x, y, color);
			x++;
		}
		y++;
	}
}

void  make_circle(t_data *img, int x_center, int y_center, int radius)
{
	int	x;
	int	y;
	int	base_color;
	int	color;

	base_color = 0x0000FF00;
	x = x_center - radius;
	while (x <= x_center + radius)
	{
		color = 0;
		y = y_center - radius;
		while (y <= y_center + radius)
		{
			if ( pow((x_center - x),2) + pow ((y_center - y), 2) <= pow(radius, 2))
			{
				my_mlx_pixel_put (img, x, y, base_color + color++);
			}
			y++;
		}
		x++;
	}
}