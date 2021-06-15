//
// Created by Federico Francois on 6/9/21.
//

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <ctype.h>
# include <sys/time.h>

enum e_msg_type {
	EAT = 1,
	SLEEP,
	FORK,
	THINK,
	DIE
};

typedef struct s_philo {
	pthread_t				thread_id;
	int						thread_num;
	int						eaten_meals;
	uint64_t				last_meal;
	uint64_t				time_to_die;
	short					is_eating;
	int						lfork;
	int						rfork;
	struct s_state			*state;
	pthread_mutex_t			mutex;
	pthread_mutex_t			count_mutex;
}	t_philo;

typedef struct s_state {
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				meals;

	uint64_t		start;

	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	main_mutex;
	t_philo			*philos;
}	t_state;

int			ft_atoi(const char *str);
t_state		*ft_init(int argc, char **argv, t_state *state);

/*
 * Monitoring
*/
int			start_routines(t_state *state);
void		*thread_start(void *arg);
void		*monitoring(void *arg);

/*
 * Utilities
*/
uint64_t	get_time(void);
int			ft_terminate(t_state *state, int sig);
void		print_msg(t_philo *philo, enum e_msg_type type);

/*
 * Actions
*/
char		*get_action(int type);
void		ft_sleep(t_philo *philo);
void		eat(t_philo *philo);
void		take_fork(t_philo *philo);
void		think(t_philo *philo);

#endif
