#include "mlx/mlx.h"
#include <stdio.h>

#define WIDTH 640
#define HEIGHT 320

typedef struct s_frac
{
	void	*mlx;
	void	*win;
}				t_frac;

int	close_esc(int keycode, t_frac *frac)
{
	if (keycode == 53)
		mlx_destroy_window(frac->mlx, frac->win);
	return (1);
}

int	close(t_frac *frac)
{
	mlx_destroy_window(frac->mlx, frac->win);
	return (1);
}

int	main(void)
{
	t_frac	fractal;

	fractal.mlx = mlx_init();
	fractal.win = mlx_new_window(fractal.mlx, WIDTH, HEIGHT, "Hello!");
	mlx_hook(fractal.win, 2, (1L << 1), close_esc, &fractal.mlx);
	mlx_hook(fractal.win, 17, 0, close, &fractal.mlx);
	mlx_loop(fractal.mlx);
	return (0);
}
