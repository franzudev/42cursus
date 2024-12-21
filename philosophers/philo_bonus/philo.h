//
// Created by Federico Francois on 6/9/21.
//

#ifndef PHILO_H
# define PHILO_H
# define FORKS_SEM "FORKS"
# define WRITE_SEM "WRITE"
# define MAIN_SEM  "MAIN"
# define PHILO_SEM "PHILO"
# define EAT_SEM   "EAT"

# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <ctype.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

enum e_msg_type {
	EAT = 1,
	SLEEP,
	FORK,
	THINK,
	DIE,
	COUNT
};

typedef struct s_philo {
	pid_t					pid;
	int						thread_num;
	int						eaten_meals;
	uint64_t				last_meal;
	uint64_t				time_to_die;
	short					is_eating;
	struct s_state			*state;
	sem_t					*mutex;
	sem_t					*count_mutex;
}	t_philo;

typedef struct s_state {
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				meals;
	int				is_dead;
	uint64_t		start;
	sem_t			*forks_mutex;
	sem_t			*write_mutex;
	sem_t			*main_mutex;
	t_philo			*philos;
}	t_state;

int			ft_atoi(const char *str);
t_state		*ft_init(int argc, char **argv, t_state *state);

/*
 * Monitoring
*/
int			start_routines(t_state *state);

/*
 * Utilities
*/
uint64_t	get_time(void);
int			ft_terminate(t_state *state, int sig);
void		print_msg(t_philo *philo, enum e_msg_type type);
void		ft_usleep(int time, t_state *all);

/*
 * Semaphores
*/
sem_t		*ft_sem_open(char *name, int value);
sem_t		*create_philo_sem(char *sem_name, int i);

/*
 * Actions
*/
char		*get_action(int type);
void		ft_sleep(t_philo *philo);
void		eat(t_philo *philo);
void		take_fork(t_philo *philo);
void		think(t_philo *philo);

#endif
