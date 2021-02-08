NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE)
SRCS = ft_printf.c helpers.c flag_manager.c flag_parser.c print_c.c \
		print_diu.c print_s.c print_per.c print_x.c print_p.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_strchr.c ft_strlen.c ft_substr.c \
		ft_atoi.c ft_isdigit.c ft_itoa.c ft_itoa_base_bonus.c \
		ft_itoa_base_ull_bonus.c ft_memset.c
OBJS = $(SRCS:c=o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
