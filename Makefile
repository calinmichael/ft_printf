name = libftprintf.a

cc = cc
cflags = -Wall -Wextra -Werror

ar = ar rcs
rm = rm -f

srcs = ft_printf.c \
	   ft_printf_char.c \
	   ft_printf_str.c \
	   ft_printf_ptr.c \
	   ft_printf_nbr.c \
	   ft_printf_unsigned.c \
	   ft_printf_hex.c 

objs = $(srcs:.c=.o)

all: $(name)

$(name): $(objs)
	$(ar) $(name) $(objs)

%.o: %.c
	$(cc) $(cflags) -c $< -o $@

clean:
	$(rm) $(objs)

fclean: clean
	$(rm) $(name)

re: fclean all

.PHONY: all clean fclean re
