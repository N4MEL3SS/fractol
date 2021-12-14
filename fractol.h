#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720

typedef struct		s_image
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
}				t_mlx;

#endif //FRACTOL_FRACTOL_H
