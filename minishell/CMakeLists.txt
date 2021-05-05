cmake_minimum_required(VERSION 3.17)
project(minishell C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -Werror -Wextra
-L/usr/local/opt/ncurses/lib -lncurses")

set(SRCS
        srcs/utils.c
        srcs/cmd/env.c
        main.c)

add_executable(minishell ${SRCS})
target_link_libraries(minishell ${CMAKE_SOURCE_DIR}/libft/libft.a)
target_link_libraries(minishell /usr/local/opt/ncurses/lib/libncurses.a)