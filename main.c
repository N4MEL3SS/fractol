#include <stdio.h>
#include "minilibx/mlx.h"

#define WIDTH 640
#define HEIGHT 320

int main()
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello!");
	mlx_loop(mlx);
}
