NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard srcs/*.c)   # All .c files in srcs/ directory
SRCS_PRINTF_DIR = ./ft_printf
SRCS_PRINTF = $(SRCS_PRINTF_DIR)/libftprintf.a
GNL_SOURCES = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o) $(GNL_SOURCES:.c=.o)  # Convert .c to .o for object files

INCLUDES = -Imlx -I/usr/include -I$(SRCS_PRINTF_DIR) -Iget_next_line
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11  # Default to Linux settings

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(SRCS_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(SRCS_PRINTF) -o $(NAME) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(SRCS_PRINTF):
	@make -C $(SRCS_PRINTF_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	make clean -C mlx/
	rm -f $(NAME)

re: fclean all
