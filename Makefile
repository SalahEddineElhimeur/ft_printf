CC = gcc
CFLAGS = -Wall -Werror -Wextra 

SRC = ft_printf.c Mondatory/ft_putchar.c Mondatory/ft_puthex.c \
Mondatory/ft_putpointer.c Mondatory/ft_putnbr.c Mondatory/ft_putnbr_un.c Mondatory/ft_putstr.c\
Bonus/ft_puthex_fg.c Bonus/ft_putpointer_helper.c Bonus/check_flags.c Bonus/helper.c \
Bonus/ft_putnbr_u_helper.c Bonus/ft_putnbr_no_minus_helper1.c \
Bonus/ft_putnbr_no_minus_helper2.c Bonus/ft_putnbr_minus_helper.c  Bonus/ft_putnbr_helper.c   

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

AR = ar crs
RM = rm -f 

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) 

bonus : $(NAME)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
