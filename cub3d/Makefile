NAME = libcub.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CMLXFLAGS = -Werror -Wextra -Wall -lmlx -framework OpenGL -framework AppKit

AR = ar -rc

RAN = ranlib

CUB_DIR = srcs/

CUB_SRCS =	event_handling/mouse_hooks.c \
			event_handling/keyboard_hhoks.c \
			game_v/game_v_reader.c \
			game_v/game_v_utilities.c \
			game_v/game_v_checks.c \
			game_v/sprites_utils.c \
			map/map_filler.c \
			map/map_checker.c \
			map/map_checker_utils.c \
			player/player_checker.c \
			player/player_mov.c \
			save/save.c \
			spell_caster/ray_caster1.c\
			spell_caster/ray_caster2.c \
			spell_caster/ray_casting.c \
			spell_caster/sprite_caster1.c \
			spell_caster/sprite_caster2.c \
			struct_manager/struct_cleaners1.c\
			struct_manager/struct_cleaners2.c\
			utils/string_utilities.c \
			utils/gen_utils.c \
			window_funcs/textures.c \
			window_funcs/win_func.c \

LIBUTILS_DIR = libutils/

LIBUTILS_SRCS =ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			get_next_line.c

BNS_DIR = srcs/bonus/

BNS_SRCS = 	mini_map.c \
			player_mov_bonus.c \
			mouse_rotation.c

CUB_DIRSRCS = $(addprefix ${CUB_DIR}, ${CUB_SRCS})

BNS_DIRSRCS = $(addprefix ${BNS_DIR}, ${BNS_SRCS})

OBJS = ${CUB_DIRSRCS:.c=.o}

LIBUTILS_DIRSRCS = $(addprefix ${LIBUTILS_DIR}, ${LIBUTILS_SRCS})

LIBUTILS_OBJS = ${LIBUTILS_DIRSRCS:.c=.o}

BNS_OBJS = $(BNS_DIRSRCS:.c=.o)

all: ${NAME}

$(NAME): ${OBJS} ${LIBUTILS_OBJS}
	@${AR} ${NAME} ${OBJS} ${LIBUTILS_OBJS}
	@${RAN} ${NAME}
	@mv ${NAME} srcs
	@make -C srcs/minilibx
	@cp srcs/minilibx/libmlx.dylib .
	@${CC} ${CMLXFLAGS} ./srcs/${NAME} srcs/main.c libmlx.dylib -o cub3D

bonus: fclean ${OBJS} ${LIBUTILS_OBJS} ${BNS_OBJS}
	@${AR} ${NAME} ${OBJS} ${LIBUTILS_OBJS} ${BNS_OBJS}
	@${RAN} ${NAME}
	@mv ${NAME} srcs
	@make -C srcs/minilibx
	@cp srcs/minilibx/libmlx.dylib .
	@${CC} ${CMLXFLAGS} ./srcs/${NAME} srcs/bonus/main_bonus.c libmlx.dylib -o cub3D

clean:
	@${RM} ${OBJS} $(BNS_OBJS) ${LIBUTILS_OBJS}
	@make clean -C srcs/minilibx

fclean: clean
	@${RM} ./srcs/${NAME}
	@${RM} libmlx.dylib
	@${RM} cub3d

re: fclean all

norme:
	@echo "Norminette is checking libcub.h \n"
	@norminette -R CheckDefine srcs/libcub.h
	@echo "\n"
	@echo "Norminette is checking bonus \n"
	@norminette srcs/bonus
	@echo "\n"
	@echo "Norminette is checking event_handling \n"
	@norminette srcs/event_handling
	@echo "\n"
	@echo "Norminette is checking game_v \n"
	@norminette srcs/game_v
	@echo "\n"
	@echo "Norminette is checking map \n"
	@norminette srcs/map
	@echo "\n"
	@echo "Norminette is checking player \n"
	@norminette srcs/player
	@echo "\n"
	@echo "Norminette is checking save \n"
	@norminette srcs/save
	@echo "\n"
	@echo "Norminette is checking spell_caster \n"
	@norminette srcs/spell_caster
	@echo "\n"
	@echo "Norminette is checking struct_manager \n"
	@norminette srcs/struct_manager
	@echo "\n"
	@echo "Norminette is checking utils \n"
	@norminette srcs/utils
	@echo "\n"
	@echo "Norminette is checking window_funcs\n"
	@norminette srcs/window_funcs
	@echo "\n"
	@echo "Norminette is checking main\n"
	@norminette srcs/main.c


.PHONY: all bonus clean fclean re
