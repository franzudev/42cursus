cmake_minimum_required(VERSION 3.17)
project(philosophers C)

set(CMAKE_C_STANDARD 11)

include_directories(philo)

add_executable(philosophers
        philo/ft_atoi.c
        philo/routines.c
        philo/utils.c
        philo/actions.c
        philo/main.c
        philo/init.c
        philo/philo.h)
