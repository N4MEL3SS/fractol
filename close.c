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
