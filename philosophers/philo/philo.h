//
// Created by Federico Francois on 6/9/21.
//

#ifndef PHILOSOPHERS_PHILO_H
#define PHILOSOPHERS_PHILO_H

#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <sys/time.h>
#include "libft-done/libft.h"

typedef struct s_philo {    /* Used as argument to thread_start() */
	pthread_t 				thread_id;        /* ID returned by pthread_create() */
	int       				thread_num;       /* Application-defined thread # */
	int 					eaten_meals;
	int						lfork;
	int						rfork;
	struct s_state			*state;
	pthread_mutex_t 		mutex;
}	t_philo;

typedef struct s_state {
	int 			num_philos;
	int 			time_die;
	int 			time_eat;
	int 			time_sleep;
	int 			meals;

	uint64_t		start;

	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t write_mutex;
	t_philo			*philos;
}	t_state;

int			ft_atoi(const char *str);
t_state		*ft_init(int argc, char **argv);
void		*thread_start(void *arg);
uint64_t	get_time();

#endif //PHILOSOPHERS_PHILO_H
