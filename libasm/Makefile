NAME	= libasm.a

AS		= @nasm
ASFLAGS	= -f macho64

SRCS	= ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s
OBJS	= $(SRCS:.s=.o)

SRCS_B	= ft_atoi_base_bonus.s ft_strchr_bonus.s
OBJS_B	= $(SRCS_B:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) $(OBJS_B)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(NAME) $(OBJS_B)
	@ar -rcs $(NAME) $(OBJS_B)