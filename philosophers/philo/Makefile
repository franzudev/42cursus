NAME=	philo

CC=		gcc

CFLAGS=	-g -Wall -Wextra -Werror

#LDFLAGS=-Llibft-done -lft

SRCS=	main.c \
		ft_atoi.c \
		init.c \
		routines.c \
		actions.c \
		utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	#make -C libft-done/
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
