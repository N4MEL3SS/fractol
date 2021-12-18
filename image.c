#include "fractol.h"

t_image	*new_image(t_mlx *mlx)
{
	t_image		*img;

	img = malloc(sizeof(t_image));
	img->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	img->ptr = mlx_get_data_addr(img->image, &img->bpp,
								 &img->stride, &img->endian);
	img->bpp /= 8;
	return (img);
}

void	image_set_pixel(t_image *image, int x, int y, int color)
{
	if (x < -WIDTH / 2 || x >= WIDTH / 2 || y < -HEIGHT / 2 || y >= HEIGHT / 2)
		return ;
	*(int *)(image->ptr + (x + y * WIDTH) * image->bpp) = color;
}

void	draw1(t_mlx *mlx_val, double coff)
{
	int		x;
	int		y;
	double	r;

	y = (HEIGHT / 2) * -1;
	while (++y < HEIGHT)
	{
		x = (HEIGHT / 2) * -1;
		while (++x < WIDTH)
		{
			r = x * x + y * y;
			if (r > WIDTH * HEIGHT / 4 || r < ((WIDTH * HEIGHT / 4) * -1))
				r = 0;
			image_set_pixel(mlx_val->image, x, y, r * coff);
		}
	}
	mlx_put_image_to_window(mlx_val->mlx, mlx_val->win,
							mlx_val->image->image, WIDTH, HEIGHT);
}

void	draw(t_mlx *mlx_val, double coff)
{
	int		x;
	int		y;
	double	r;

	y = (HEIGHT / 2) * -1;
	while (++y < HEIGHT)
	{
		x = (HEIGHT / 2) * -1;
		while (++x < WIDTH)
			image_set_pixel(mlx_val->image, x, y, 100 * coff);
	}
	mlx_put_image_to_window(mlx_val->mlx, mlx_val->win,
							mlx_val->image->image, WIDTH / 2, HEIGHT / 2);
}

int	render(int keycode, t_mlx *mlx_val)
{
	if (keycode == 49)
	{
		mlx_val->coff += 0.1 * mlx_val->k;
		if (mlx_val->coff > 100000 && mlx_val->k == 1)
			mlx_val->k = -1;
		if (mlx_val->coff < 1 && mlx_val->k == -1)
			mlx_val->k = 1;
		draw(mlx_val, mlx_val->coff);
	}
	return (1);
}
