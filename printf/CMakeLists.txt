cmake_minimum_required(VERSION 3.17)
project(printf C)

set(CMAKE_CXX_STANDARD 89)

include_directories(include)

set(SOURCES
        test.c
        ft_printf.c
        helpers.c
        flag_manager.c
        flag_parser.c
        print_x.c
        print_u.c
        print_s.c
        print_per.c
        print_p.c
        print_diu.c
        print_c.c
        libft/ft_atoi
        libft/ft_isdigit
        libft/ft_itoa
        libft/ft_memset
        libft/ft_putchar_fd
        libft/ft_itoa_base_bonus
        libft/ft_itoa_base_ull_bonus.c
        libft/ft_putstr_fd
        libft/ft_strchr
        libft/ft_strlen
        libft/ft_substr
        )

set(HEADER include/libft.h include/ft_printf.h)

add_executable(printf ${HEADER} ${SOURCES})