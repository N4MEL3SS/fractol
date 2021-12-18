#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720

typedef struct s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}					t_image;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_image		*image;
	double		coff;
	int			k;
}				t_mlx;

t_image		*new_image(t_mlx *mlx);
void		draw(t_mlx *mlx_val, double coff);
int			render(int keycode, t_mlx *mlx_val);

int			close_win(t_mlx *frac);
int			close_esc(int keycode, t_mlx *frac);

#endif //FRACTOL_H
