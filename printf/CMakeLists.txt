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
        ft_atoi
        ft_isdigit
        ft_itoa
        ft_memset
        ft_putchar_fd
        ft_itoa_base_bonus
        ft_itoa_base_ull_bonus.c
        ft_putstr_fd
        ft_strchr
        ft_strlen
        ft_substr
        )

set(HEADER libft.h ft_printf.h)

add_executable(printf ${HEADER} ${SOURCES})