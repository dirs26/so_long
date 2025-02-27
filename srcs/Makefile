NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:src/%.c=src/%.o)

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	INCLUDES = -I/opt/X11/include -Imlx
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	make clean -C mlx/
	rm -f $(NAME)

re: fclean all
