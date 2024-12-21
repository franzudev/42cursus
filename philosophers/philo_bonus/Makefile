NAME=	philo_bonus

CC=		gcc

CFLAGS=	-g -Wall -Wextra -Werror

SRCS=	main.c \
		ft_atoi.c \
		init.c \
		routines.c \
		actions.c \
		utils.c \
		semaphores.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
