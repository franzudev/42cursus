cmake_minimum_required(VERSION 3.19)
project(philo_bonus2)

set(CMAKE_CXX_STANDARD 98)

add_executable(philo_bonus2 actions.c ft_atoi.c init.c  routines.c semaphores.c utils.c main.c)
