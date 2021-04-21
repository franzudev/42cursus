# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffrancoi <ffrancoi@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 15:50:15 by ffrancoi          #+#    #+#              #
#    Updated: 2021/04/21 15:50:17 by ffrancoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
NAME2 = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -Llibft -lft

SRCS_CHECKER = check_instruction.c exec_instruction.c operations.c gnl.c checker.c atoi_2.c utils.c check_args.c
SRCS_SWAP = check_instruction.c topolino.c pp_utils.c phase_seven.c paperino_utils.c exec_instruction.c paperino.c pincopallino.c quicksort.c operations.c gnl.c push_swap.c atoi_2.c utils.c check_args.c

all: $(NAME) $(NAME2)

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(SRCS_CHECKER)

$(NAME2): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME2) $(SRCS_SWAP)

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	rm -f $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
