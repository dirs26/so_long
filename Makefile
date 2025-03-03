NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard srcs/*.c)   # All .c files in srcs/ directory
OBJS = $(SRCS:.c=.o)           # Convert .c to .o for object files
INCLUDES = -I/usr/include -Imlx

ifeq ($(shell uname), Linux)
    INCLUDES = -Imlx -I/usr/include
    MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
    INCLUDES = -Imlx -I/opt/X11/include
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
