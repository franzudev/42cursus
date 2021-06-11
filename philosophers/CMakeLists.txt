cmake_minimum_required(VERSION 3.19)
project(philosophers C)

set(CMAKE_C_STANDARD 11)

include_directories(philo)

add_executable(philosophers
        philo/ft_atoi.c
        philo/main.c
        philo/init.c
        philo/philo.h)
