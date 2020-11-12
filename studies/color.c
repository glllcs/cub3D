#include "learning.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		get_b(int trgb)
{
	return (trgb & 0xFF);
}

int		get_rgb(int trgb)
{
	return (trgb & 0xFFFFFF);
}

int		add_shade(double distance, int color)
{
	int	transp;

	if (distance < 0 || distance > 1)
		transp = get_t(color);
	else 
		transp = distance * 255;
	return (transp << 24 | get_rgb(color));
}

int		get_opposite (int color)
{
	return (get_t(color) << 24 | (0xFFFFFF - get_rgb(color)));
}
