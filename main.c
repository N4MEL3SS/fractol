#include "mlx_linux/mlx.h"
#include "fractol.h"

int	close_esc(int keycode, t_mlx *frac)
{
	printf("key = %i\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(frac->mlx, frac->win);
		exit(0);
	}
	return (1);
}

int	close_win(t_mlx *frac)
{
	mlx_destroy_window(frac->mlx, frac->win);
	exit(0);
}

t_image	*new_image(t_mlx *mlx)
{
	t_image		*img;

	img = malloc(sizeof(t_image));
	img->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->stride,
								 &img->endian);
	img->bpp /= 8;
	return (img);
}


void	image_set_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(int *)(image->ptr + (x + y * WIDTH) * image->bpp) = color;
}

void	draw(t_mlx *mlx_val, double coff)
{
	int	x;
	int	y;
	int r;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			r = x * x + y * y;
			if (r > WIDTH * HEIGHT / 2)
				r = 0;
			image_set_pixel(mlx_val->image, x, y, r * coff);
		}
	}
	mlx_put_image_to_window(mlx_val->mlx, mlx_val->win,
							mlx_val->image->image, 0, 0);
}

int	main(void)
{
	t_mlx	mlx_val;
	double	coff;
	int 	k;

	coff = 0;
	k = 1;
	mlx_val.mlx = mlx_init();
	mlx_val.win = mlx_new_window(mlx_val.mlx, WIDTH, HEIGHT, "fractol");
	mlx_val.image = new_image(&mlx_val);
	while (1)
	{
		coff += 0.1 * k;
		if (coff > 50 && k == 1)
			k = -1;
		if (coff < 1 && k == -1)
			k = 1;
		draw(&mlx_val, coff);
		mlx_hook(mlx_val.win, 17, 0, close_win, &mlx_val.mlx);
		mlx_hook(mlx_val.win, 2, 0, close_esc, &mlx_val.mlx);
	}
	mlx_loop(mlx_val.mlx);
	return (0);
}
