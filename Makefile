CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs
RM = rm -f
LIBFT = libft
LIBFT_LIB = libft.a
NAME = libftprintf.a
HEADER = header

SRC = ft_printf.c \
	   parsing_ft.c \
	   print_c.c \
	   print_s.c \
	   print_num.c \
	   print_process.c \
	   ft_putnbr.c \
	   ft_puthex.c \
	   add.c \
	   print_percent.c


SRCS = $(addprefix ./src/, $(SRC))
OBJS = $(SRCS:.c=.o)

.c.o : $(SRCS)
		$(CC) $(CFLAGS) -I$(HEADER) -I$(LIBFT) -c -o $@ $<

$(NAME) : $(OBJS)
		make -C $(LIBFT)/
		cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
		$(AR) $(ARFLAGS) $@ $^

all : $(NAME)


clean :
		$(RM) $(OBJS) $(OBJS_B)
		make clean -C $(LIBFT)/

fclean : clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT)/

re: fclean all

.PHONY: all, clean, fclean, re, bonus
