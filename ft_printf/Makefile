NAME = libftprintf.a

SOURCES = ft_putchar.c ft_putnbr.c ft_puthex.c ft_putunbr.c ft_putptr.c ft_putstr.c ft_printf.c
OBJECTS = $(SOURCES:.c=.o) 

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = ft_printf.h
RM = rm -f

all: $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	
clean:                                                                         
		$(RM) $(OBJECTS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

