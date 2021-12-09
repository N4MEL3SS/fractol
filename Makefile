NAME = fractol
OS = $(shell uname)

CC = clang
FLAGS = -Wall -Wextra -Werror
FRAME_LINUX = -lXext -lX11
FRAME_MAC = -framework OpenGL -framework AppKit
SRC = main.c

ifeq ($(OS), Linux)
	MLX = ./mlx_linux/
	MLX_LNK = -L $(MLX) -l mlx $(FRAME_LINUX)
else
	MLX = ./mlx/
	MLX_LNK = -L $(MLX) -l mlx $(FRAME_MAC)
endif

OBJ = $(SRC:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: clean fclean all

.PHONY: clean fclean re all
